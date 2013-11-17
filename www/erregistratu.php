<?php 
	function erregistratuErabiltzailea($pErab,$pEmaila,$pPass){
		$mota='identifikatu';
		include 'konexioa.inc';
		mysql_select_db($datuBasea,$link);
		$pPass=sha1($pPass);
		$query="SELECT * FROM `Alarma`.`erabiltzaile` WHERE `erabiltzaile`.`nicka`='$pErab' OR `erabiltzaile`.`emaila`='$pEmaila'";
		$query2="INSERT INTO `erabiltzaile`(`iderab`, `nicka`, `emaila`, `pasahitza`, `azkenkonexioa`) VALUES(NULL,'$pErab','$pEmaila','$pPass','Ez da inoiz konektatu')";
		$emaitza=mysql_query($query,$link);
			
		if (mysql_num_rows($emaitza)>=1) {
			echo "<script type='text/javascript'> alert('Errorea, Erabiltzailea erregistratua lehenagotik'); window.location='index.php';</script>";
			return false;
		}else{
			if(mysql_num_rows($emaitza)==0){
				$emaitza2=mysql_query($query2,$link);
				echo "<script type='text/javascript'> alert('Erregistratu zara!'); window.location='erabiltzaile.php';</script>";
				session_start();
				return true;
			}else{
				echo "<script type='text/javascript'> alert('Errorea, ez zara erregistratu!'); window.location='index.php';</script>";
				return false;
			}
		}
		unset($mota);
	}
?>
<div id="wrapper">
	<div id="edukiontzia">
		<div id="edukia">
			<?php
				$erab=$_POST["Eizena"];
				$pass=$_POST["Epasahitza"];
				$Emaila=$_POST["EEmaila"];
				erregistratuErabiltzailea($erab,$Emaila,$pass);
			?>
		</div><!-- #edukia-->
	</div><!-- #edukiontzia-->

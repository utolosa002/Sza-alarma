<?php 
 /*
Funtzio honek erabiltzaile bat erregistratzen du, iada erregistratua ez badago.
Erabiltzailearen id-a, emaila eta pasahitza jaso behar ditu.
Boolearra itzultzen du.
*/
	function erregistratuErabiltzailea($pErab,$pEmaila,$pPass){
		$mota='identifikatu';
		include 'konexioa.inc';
		mysql_select_db($datuBasea,$link);
		$pPass=sha1($pPass);
		$query="SELECT `e`.`nicka` FROM `Erabiltzaile` as `e` WHERE `e`.`nicka`='$pErab' OR `e`.`emaila`='$pEmaila'";
		$query2="INSERT INTO `Erabiltzaile`(`iderab`, `nicka`, `emaila`, `pasahitza`, `azkenkonexioa`) VALUES('','$pErab','$pEmaila','$pPass','Ez da inoiz konektatu')";
		$emaitza=mysql_query($query,$link);
		if (mysql_num_rows($emaitza)>0) {
			echo "<script type='text/javascript'> alert('Erabiltzailea erregistratua lehenagotik!'); window.location='index.php';</script>";
			return false;
		}else{
			if(mysql_num_rows($emaitza)==0){
				$emaitza2=mysql_query($query2,$link);
				if(mysql_affected_rows()==1) {
					session_start();
					return true;
				}else{/*0 edo -1 da erantzuna*/
					return false;
				}
			}else{
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
				if(erregistratuErabiltzailea($erab,$Emaila,$pass)){
					echo "<script type='text/javascript'> alert('Erregistratu zara!'); window.location='erabiltzaile.php';</script>";
				}else{
					echo "<script type='text/javascript'> alert('Ez zara erregistratu!'); window.location='index.php';</script>";
				}
			?>
		</div><!-- #edukia-->
	</div><!-- #edukiontzia-->

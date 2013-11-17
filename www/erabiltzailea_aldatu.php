<?php
	function elkarbanatu($pId,$pEgoera){
		include 'konexioa.inc';
		mysql_select_db($datuBasea,$link);
		$query="INSERT INTO `erab_alarma` as `ea` SET `ea`.`Segoera`=\"$pEgoera\" WHERE `s`.`Sid`=\"$pId\"";
		$emaitza=mysql_query($query,$link);
		if(mysql_num_rows($emaitza)==0){
			echo "$pId aldatu duzu";
			return true;
		}else{
			echo "<script type='text/javascript'> alert('Kasu! Ezin izan zaio $pId-ri baimena eman!'); </script>";
			return false;
			
		}
	}
?>
<?php
	if(isset($_POST['hautatu'])) {
		$pId=$_POST['hautatu'];
		if(isset($_POST['eBanatu'])) {
			if(elkarbanatu($pId)){
				header("Location: ./erabiltzaile.php?erab");
			}else{
				header("Location: ./erabiltzaile.php");
			}
		}else{
		header("Location: ./erabiltzaile.php");
		}
	}else{
		header("Location: ./erabiltzaile.php?erab");
	}
?>

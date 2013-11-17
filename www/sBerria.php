<?php
	function gehituSentsorea($Aid,$sIzena){
		include 'konexioa.inc';
		mysql_select_db($datuBasea,$link);
		$query="INSERT INTO `Sentsore` (`Sid`, `Jalarma`, `Sizena`, `Segoera`) VALUES (\"\", $Aid, \"$sIzena\", 1)";
		$sentsOK=mysql_query($query,$link);
 		if(mysql_num_rows($sentsOK)==0){
			echo "<script type='text/javascript'> alert('Ez duzu sentsorerik sartu'); </script>";
			return false;
		}else{
			return true;
		}
	}

	$i=0; 
	$paId=$_POST['aid'];
	foreach ($_POST['sizena'] as $index => $pIz){
		gehituSentsorea($paId,$pIz);
	}	
	header("Location: ./erabiltzaile.php?alarmak");
?>

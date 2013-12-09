<?php
/*
Funtzio honek sentsorea gehitzen du.
Alarmaren ida eta sentsoren izena pasa behar zaizkio
Boolearra itzultzen du.
*/
	function gehituSentsorea($Aid,$sIzena){
		include 'konexioa.inc';
		mysql_select_db($datuBasea,$link);
		$query="INSERT INTO `Sentsore` (`sid`, `idalarma`, `sizena`, `segoera`) VALUES (\"\", $Aid, \"$sIzena\", 1)";
		$sentsOK=mysql_query($query,$link);
 		if(mysql_affected_rows()==(-1 || 0)){
			return false;
		}else{
			return true;
		}
	}

	$i=0; 
	$paId=$_POST['aid'];
	foreach ($_POST['sizena'] as $index => $pIz){
		if (gehituSentsorea($paId,$pIz)){
		}else{
			header("Location: ./erabiltzaile.php?error&e=sgehi");
		}
	}	
	header("Location: ./erabiltzaile.php?alarmak");
?>
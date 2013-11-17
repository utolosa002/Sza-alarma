<?php 
	function sortuAlarma($pAIzena){
		include 'konexioa.inc';
		mysql_select_db($datuBasea,$link);
		$erabil=$_SESSION["erab"];
		$query="INSERT INTO `Alarma`(`alarmaid`, `aizena`, `aegoera`) VALUES (\"\",  \"$pAIzena\", 0)";
		$Alarma=mysql_query($query,$link);
		$pIda = mysql_insert_id();
		$query1="SELECT `e`.`iderab` FROM `erabiltzaile` as `e` WHERE `e`.`nicka` =\"$erabil\"";
		$pIde=mysql_query($query1,$link);

		while($ide= mysql_fetch_row($pIde)){
			foreach ($ide as $balioa){
      				$pIde = $balioa[0];
			}
		}

		$query3="INSERT INTO `erab_alarma`(`iderab`, `alarma`) VALUES (\"$pIde\",\"$pIda\")";
		$Alarmak2=mysql_query($query3,$link);
		if(mysql_num_rows($Alarma2)<0){
			echo "<script type='text/javascript'> alert('Ez duzu sentsorerik sartu'); </script>";
			return 0;
		}else{
			return $pIda;
		}
		
	}

	function gehituSentsorea($sIzena,$aId){
		include 'konexioa.inc';
		mysql_select_db($datuBasea,$link);

		$query="INSERT INTO `Sentsore` (`Sid`, `Jalarma`, `Sizena`, `Segoera`) VALUES (\"\", $aId, \"$sIzena\", 1)";
		$sentsOK=mysql_query($query,$link);
 		if(mysql_num_rows($sentsOK)==0){
			echo "<script type='text/javascript'> alert('Ez duzu sentsorerik sartu'); </script>";
			return false;
		}else{
			return true;
		}
	}

	$i=1; 
	$pIzena=$_POST['Aizena'];
	$aId=sortuAlarma($pIzena);
	if ($aId>0){
		foreach ($_POST['sizena'] as $index => $pIz){
			gehituSentsorea($pIz,$aId);
		}	
		header("Location: ./erabiltzaile.php?sentsoreak");
	}else{
		header("Location: ./erabiltzaile.php");
	}
?>

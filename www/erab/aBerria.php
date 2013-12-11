<?php include_once 'access.inc' ?>
<?php
/*
Funtzio honek alarma berri bat sortzen du datu basean eta alarma berri horren ida 
erabiltzailearenarekin lotzen du. Honela uneko erabiltzaileari alarma horren jabetza 
ematen zaio.
*/
	function sortuAlarma($pAIzena,$pAkti){
		include 'konexioa.inc';
		mysql_select_db($datuBasea,$link);
		$erabil=$_SESSION["erab"];
		$query="SELECT `e`.`iderab` FROM `Erabiltzaile` as `e` WHERE `e`.`nicka` =\"$erabil\"";
		$pIde=mysql_query($query,$link);
		while($ide= mysql_fetch_row($pIde)){
			foreach ($ide as $balioa){
      				$pIde = $balioa;
			}
		}
		$query1="INSERT INTO `Alarma`(`idalarma`, `aizena`, `aegoera`, `jabeiderab`) VALUES (\"\",  \"$pAIzena\", \"$pAkti\",\"$pIde\")";
		$Alarma1=mysql_query($query1,$link);
		$pIda = mysql_insert_id();
		if(mysql_affected_rows()==-1){
			return 0;
		}
		$query2="INSERT INTO `Erab_alarma`(`iderab`, `idalarma`) VALUES (\"$pIde\",\"$pIda\")";
		$Alarmak2=mysql_query($query2,$link);
		if(mysql_affected_rows()==-1){
			return 0;
		}else{
			return $pIda;
		}
		
	}

/*
Funtzio honek sentsore berri bat sortzen du datu basean.
Sentsore izena eta alarmaren id-a pasa behar zaizkio.
Boolerra itzultzen du.
*/
	function gehituSentsorea($sIzena,$aId){
		include 'konexioa.inc';
		mysql_select_db($datuBasea,$link);
		$query="INSERT INTO `Sentsore` (`sid`, `idalarma`, `sizena`, `segoera`) VALUES (\"\", $aId, \"$sIzena\", 1)";
		$sentsOK=mysql_query($query,$link);
 		if(mysql_affected_rows()==(-1 || 0)){
			return false;
		}else{
			return true;
		}
	}

	$pIzena=$_POST['Aizena'];
	if(isset($_POST['egoera']) && $_POST['egoera'] == 'aktibatuta') {
		$pEgoera=1;
	}else{
		$pEgoera=0;
	}
	$aId=sortuAlarma($pIzena,$pEgoera);
	if ($aId>0){
		foreach ($_POST['sizena'] as $index => $pIz){
			if(!gehituSentsorea($pIz,$aId)){
				header("Location: ./erabiltzaile.php?error&e=sgehi");
			}
		}	
		header("Location: ./erabiltzaile.php?alarmak");
	}else{
		header("Location: ./erabiltzaile.php?error&e=salarma");
	}
?>

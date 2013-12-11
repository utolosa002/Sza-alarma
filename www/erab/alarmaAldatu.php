<?php include 'access.php' ?>  
<?php 
/*
Funtzio honek alarmaren egora aldatzen du.
alarmaren ida eta egoera pasa behar zaizkio.
boolearra itzultzen du.
*/
	function aldatu_egoera($pId,$pEgoera){
		include 'konexioa.inc';
		mysql_select_db($datuBasea,$link);
		$query="UPDATE `Alarma` SET `aegoera`=\"$pEgoera\" WHERE `idalarma`=\"$pId\"";
		$emaitza=mysql_query($query,$link);
		if(mysql_affected_rows()<=0){
			return false;
		}else{
			return true;
		}
	}
/*
Funtzio honek alarma ezabatzen du.
Alarmaren ida pasa behar zaio.
integer bat itzultzen du.*/
function alarma_ezabatu($pId){
		include 'konexioa.inc';
		mysql_select_db($datuBasea,$link);
		$query="DELETE FROM `Alarma` WHERE `idalarma`=\"$pId\"";
		$emaitza=mysql_query($query,$link);
		if(mysql_affected_rows()==1){
			$queryErab_alarma="DELETE FROM `Erab_alarma` WHERE `idalarma`=\"$pId\"";
			$emaErab_alarma=mysql_query($queryErab_alarma,$link);
			if(mysql_affected_rows()>=1){
				$querySentsore="DELETE FROM `Sentsore` WHERE `jalarma`=\"$pId\"";
				$emaSentsore=mysql_query($querySentsore,$link);
				if(mysql_affected_rows()>=1){
					return 1;
					/*sentsoreren bat ere ezabatua*/
				}else{
					return 1;
					/*sentsorerik ez du ezabatu baino alarma bai*/
				}
			}else{
				return 0;
				/*Erab_Alarma loturak ez dira ezabatu*/
			}
		}else{
			return 0;
			/*ez da Alarma ezabatu*/
		}
	}

?>
<?php 
	if(isset($_POST['hautatu'])) {
		$pId=$_POST['hautatu'];
		$egoera="alarma".$pId."3";
		$pEgoera=$_POST[$egoera];
		if($pEgoera==="Ixilik"){
			$pEgoeraBerria="1";
		}else{
			$pEgoeraBerria="0";
		}
		if(isset($_POST['aAldatu'])) {
			if(aldatu_egoera($pId,$pEgoeraBerria)){
				header("Location: ./erabiltzaile.php?alarmak");
			}else{
				header("Location: ./erabiltzaile.php?error&e=aaldatu");
			}
		}else if(isset($_POST['aBanatu'])) {
			header("Location: ./erabiltzaile.php?elkarbanatu&al=$pId");
		}else if(isset($_POST['aIkusi'])) { 
			header("Location: ./erabiltzaile.php?alarma&al=$pId");
		}else if(isset($_POST['sGehitu'])) { 
			header("Location: ./erabiltzaile.php?sen_gehitu&sen=$pId");
		}else if(isset($_POST['aEzabatu'])) {
			$ezabatua=alarma_ezabatu($pId);
			if($ezabatua==1){
				header("Location: ./erabiltzaile.php?alarmak");
			}elseif($ezabatua==0){
				header("Location: ./erabiltzaile.php?error&e=aezabatu");
			}
		}else{
			header("Location: ./erabiltzaile.php");
		}
	}else{
		/*alarmarik ez da hautatu*/
		header("Location: ./erabiltzaile.php?alarmak");
	}
?>

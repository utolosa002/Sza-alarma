<?php include 'access.inc' ?>
<?php 
/*
Funtzio honek sentsoreren egoera aldatzen du.
Sentsorearen ida eta sentsoren izena pasa behar zaizkio.
Boolearra itzultzen du.
*/
	function aldatu_egoera($pId,$pEgoera){
		include 'konexioa.inc';
		mysql_select_db($datuBasea,$link);
		$query="UPDATE `Sentsore` as `s` SET `s`.`segoera`=\"$pEgoera\" WHERE `s`.`sid`=\"$pId\"";
		$emaitza=mysql_query($query,$link);
		if(mysql_affected_rows()==1){
			return true;
		}else{
			return false;
			
		}
	}	
/*
Funtzio honek sentsorea ezabatzen du.
Sentsorearen ida pasa behar zaio.
Boolearra itzultzen du.
*/
	function ezabatu_sentsorea($pId){
		include 'konexioa.inc';
		mysql_select_db($datuBasea,$link);
		$query="DELETE FROM `Sentsore` WHERE `sid`=\"$pId\"";
		$emaitza=mysql_query($query,$link);
		if(mysql_affected_rows()==1){
			return true;
		}else{
			return false;
		}
	}
?>
<?php 
	if(isset($_POST['hautatu'])) {
		$pId=$_POST['hautatu'];
		if(isset($_POST['sAldatu'])) {
			$egoera="sen".$pId."3";
			$pEgoera=$_POST[$egoera];
			if($pEgoera==="Desaktibatuta"){
				$pEgoeraBerria="1";
			}else{
				$pEgoeraBerria="0";
			}
			if(aldatu_egoera($pId,$pEgoeraBerria)){
				header("Location: ./erabiltzaile.php?sentsoreak");
			}else{
				header("Location: ./erabiltzaile.php?error&e=segoera");
			}
		}else if(isset($_POST['sEzabatu'])) { 
			if(ezabatu_sentsorea($pId)){	
				header("Location: ./erabiltzaile.php?sentsoreak");
			}else{
				header("Location: ./erabiltzaile.php?error&e=sezaba");
			}
		}else{
			header("Location: ./erabiltzaile.php?sentsoreak");
		}	
	}else{
		header("Location: ./erabiltzaile.php?sentsoreak");
	}
?>

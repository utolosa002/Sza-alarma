<?php 
	function aldatu_egoera($pId,$pEgoera){
		include 'konexioa.inc';
		mysql_select_db($datuBasea,$link);
		$query="UPDATE `Sentsore` as `s` SET `s`.`Segoera`=\"$pEgoera\" WHERE `s`.`Sid`=\"$pId\"";
		$emaitza=mysql_query($query,$link);
		if(mysql_num_rows($emaitza)==0){
			echo "$pId aldatu duzu";
			return true;
		}else{
			echo "<script type='text/javascript'> alert('Kasu! Ezin izan zaio $pId-ri baimena eman!'); </script>";
			return false;
			
		}
	}	

	function ezabatu_sentsorea($pId){
		include 'konexioa.inc';
		mysql_select_db($datuBasea,$link);
		$query="DELETE FROM `Sentsore` WHERE `Sid`=\"$pId\"";
		$emaitza=mysql_query($query,$link);
		if(mysql_num_rows($emaitza)==0){
			echo "$pId ezabatu duzu";
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
				header("Location: ./erabiltzaile.php");
			}
		}else if(isset($_POST['sEzabatu'])) { 
			if(ezabatu_sentsorea($pId)){	
				header("Location: ./erabiltzaile.php?sentsoreak");
			}else{
				header("Location: ./erabiltzaile.php");
			}
		}else{
		header("Location: ./erabiltzaile.php");
		}	
	}else{
		header("Location: ./erabiltzaile.php?sentsoreak");
	}
?>

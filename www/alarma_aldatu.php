<?php include 'access.php' ?>  
<?php 
	function aldatu_egoera($pId,$pEgoera){
		include 'konexioa.inc';
		mysql_select_db($datuBasea,$link);
		$query="UPDATE `Alarma` SET `aegoera`=\"$pEgoera\" WHERE `alarmaid`=\"$pId\"";
		$emaitza=mysql_query($query,$link);
		if(mysql_num_rows($emaitza)==0){
			$emaitza=mysql_query($query,$link);
			echo "<script type='text/javascript'>alert('$pId-ri egoera aldatu diozu'); </script>";
			return true;
		}else{
			echo "<script type='text/javascript'> alert('Kasu! Ezin izan zaio $pId-ri egoera aldatu!'); </script>";
			return false;
		}
	}

	function alarma_ezabatu($pId){
		include 'konexioa.inc';
		mysql_select_db($datuBasea,$link);
		$query="DELETE FROM `Alarma` WHERE `alarmaid`=\"$pId\"";
		$query1="DELETE FROM `erab_alarma` WHERE `alarma`=\"$pId\"";
		$query2="DELETE FROM `Sentsore` WHERE `Jalarma`=\"$pId\"";
		$emaitza=mysql_query($query,$link);
		if(mysql_num_rows($emaitza)==0){
			$emaitza1=mysql_query($query1,$link);
			if(mysql_num_rows($emaitza1)==0){
				$emaitza2=mysql_query($query2,$link);
				if(mysql_num_rows($emaitza2)==0){
					echo "<script type='text/javascript'>alert('$pId alarma ezabatu duzu'); </script>";
					return true;
				}else{
					echo "<script type='text/javascript'>alert('Agian ez zuen sentsorerik, ezin izan da sentsorik ezabatu'); </script>";
					return false;
				}
			}else{
				echo "<script type='text/javascript'>alert('Ezin izan da jaberik lortu.'); </script>";
				return false;
			}
		}else{
			echo "<script type='text/javascript'> alert('Kasu! Ezin izan da alarma $pId ezabatu!'); </script>";
			return false;
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
			aldatu_egoera($pId,$pEgoeraBerria);
			header("Location: ./erabiltzaile.php?alarmak");
		}else if(isset($_POST['aBanatu'])) { 
			header("Location: ./erabiltzaile.php?elkarbanatu&al=$pId");
		}else if(isset($_POST['sGehitu'])) { 
			header("Location: ./erabiltzaile.php?sen_gehitu&sen=$pId");
		}else if(isset($_POST['aEzabatu'])) {
			alarma_ezabatu($pId);
			header("Location: ./erabiltzaile.php?alarmak");
		}else{
			header("Location: ./erabiltzaile.php");
		}
	}else{
		/*alarmarik ez da hautatu*/
		header("Location: ./erabiltzaile.php?alarmak");
	}
?>

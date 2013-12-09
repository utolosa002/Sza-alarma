<?php
 /*
Funtzio honek alarma beste erabiltzaile batekin elkarbanatzen du. 
Erabiltzailearen ida eta alarmaren id-a jaso behar ditu.
Integer bat itzultzen du.
*/
	function elkarbanatu($pIde,$pIda){
		include 'konexioa.inc';
		mysql_select_db($datuBasea,$link);
		$erabil=$_SESSION["erab"];
		if($erabil==$pIde) {
			$query="INSERT INTO `Erab_alarma`(`iderab`, `idalarma`) VALUES (\"$pIde\",\"$pIda\")";
			$emaitza=mysql_query($query,$link);
			if(mysql_affected_rows()<=0){
				return 0;
			}else{
				return 1;
			}
		}else{
			return -1;
		}
	}
?>
<?php
	if(isset($_POST['idalarma'])) {
		$pIda=$_POST['idalarma'];
		if(isset($_POST['hautatu'])) {
			$pIde=$_POST['hautatu'];
			if(isset($_POST['eBanatu'])) {
				if(elkarbanatu($pIde,$pIda)==1){
					header("Location: ./erabiltzaile.php?erab");
				}elseif(elkarbanatu($pIde,$pIda)==0){
					header("Location: ./erabiltzaile.php?error&e=elkar");
				}elseif(elkarbanatu($pIde,$pIda)==-1){
					header("Location: ./erabiltzaile.php?error&e=ajabea");
				}
			}else{
				header("Location: ./erabiltzaile.php?error&e=elkar");
			}
		}else{
			header("Location: ./erabiltzaile.php?error&e=elkar");
		}
	}else{
		header("Location: ./erabiltzaile.php?error&e=elkar");
	}
?>

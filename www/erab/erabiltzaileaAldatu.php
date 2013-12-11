<?php include_once 'access.inc' ?>  
<?php
 /*
Funtzio honek alarma beste erabiltzaile batekin elkarbanatzen du. 
Erabiltzailearen ida eta alarmaren id-a jaso behar ditu.
Integer bat itzultzen du.
*/
	function elkarbanatu($pIde,$pIda){
		include 'konexioa.inc';
		mysql_select_db($datuBasea,$link);
		$erab=$_SESSION["erab"];
		$queryIdE="SELECT `e`.`iderab` FROM `Erabiltzaile` AS `e` WHERE `e`.`nicka` =\"$erab\"";
		$emaIde=mysql_query($queryIdE,$link);
		$unekoerabil= mysql_fetch_row($emaIde);

		$queryIda="SELECT `a`.`jabeiderab` FROM `Alarma` AS `a` WHERE `a`.`idalarma` =\"$pIda\"";
		$emaIda=mysql_query($queryIda,$link);
		$alarmajabea= mysql_fetch_row($emaIda);
		
		if($unekoerabil==$alarmajabea) {
			$queryIn="INSERT INTO `Erab_alarma`(`iderab`, `idalarma`) VALUES (\"$pIde\",\"$pIda\")";
			$emaitzaInsert=mysql_query($queryIn,$link);
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
				}else{
					header("Location: ./erabiltzaile.php?error&e=aelkarjabea");
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

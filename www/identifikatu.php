<?php 
 /*
Funtzio honek erabiltzaile baten sesioa hasten du erregistratua badago lehenagotik.
Erabiltzailearen nick-a, eta pasahitza jaso behar ditu.
Pasahitza eta erabiltzailea ondo sartzen direnenan soilik hasten da sesioa.
Boolearra itzultzen du, baino lehenago script bidez adierazten du.
*/
	function identifikatuErabiltzailea($pErab,$pPass){
		include './erab/konexioa.inc';
		mysql_select_db($datuBasea,$link);
		$data=getdate();
		$d = $data['mday'];
		$m = $data['mon'];
		$y = $data['year'];
		$queryNicka="SELECT * FROM Erabiltzaile WHERE nicka='$pErab'";
		$queryEmaila="SELECT * FROM `Erabiltzaile` AS `e` WHERE `emaila`='$pErab'";
		$queryErab="SELECT `e`.`nicka` FROM `Erabiltzaile` AS `e` WHERE `emaila`='$pErab'";	
		$queryAzkenkon="UPDATE `Erabiltzaile` SET `azkenkonexioa`='$y-$m-$d' WHERE `nicka`='$pErab' OR `emaila`='$pErab'";
		$emaNicka=mysql_query($queryNicka,$link);
		$nickaInt=mysql_num_rows($emaNicka);
		if ($nickaInt<=0) {// nicka ez dago!
	   	$emaEmaila=mysql_query($queryEmaila,$link);
	   	$emailaInt=mysql_num_rows($emaEmaila);
			if ($emailaInt<=0) { //emaila ere ez dago!
				echo "<script type='text/javascript'> alert('Errorea, Ez da aurkitu erabiltzaile hori'); window.location='./index.php'; </script>";
				return false;
			}else{
	         	if($emailaInt==1){//emaila badago
						$erabiltzaileBaimendua = mysql_fetch_array($emaEmaila);
						if ($erabiltzaileBaimendua['pasahitza']==sha1($pPass)){
							session_start();
							$emaitzaUpdate=mysql_query($queryAzkenkon,$link);
							
							$emaErab=mysql_query($queryErab,$link);
							$pErab = mysql_fetch_row($emaErab);
							
							$_SESSION["erab"]=$pErab[0];
							return true;
						}else{
							echo "<script type='text/javascript'> alert('Errorea, OkerrekO pasahitza!'); window.location='./index.php';</script>";
							return false;
						}
					}else{
						echo "<script type='text/javascript'> alert('Errorea, Ez da aurkitu erabiltzaile hori');  window.location='./index.php';</script>";
						return false;
					}
 			}
		}else{
			if($nickaInt==1){ //nicka  aurkitu da
				$erabiltzaileBaimendua = mysql_fetch_array($emaNicka);
				if ($erabiltzaileBaimendua['pasahitza']==sha1($pPass)){
					session_start();
					$emaitzaUpdate=mysql_query($queryAzkenkon,$link);
					$_SESSION["erab"]=$pErab;
					return true;
				}else{
					echo "<script type='text/javascript'> alert('Errorea, OkerrekO pasahitza!'); window.location='./index.php'; </script>";
					return false;
				}
			}else{
				echo "<script type='text/javascript'> alert('Errorea, OkerrekO erabiltzailea!');  window.location='./index.php';</script>";
				return false;
			}
		}
	}
?>
<?php 
	$erab=$_POST["izena"];
	$pass=$_POST["pasahitza"];
	if(identifikatuErabiltzailea($erab,$pass)) {		
		header("Location: ./erab/erabiltzaile.php");
	}
?>

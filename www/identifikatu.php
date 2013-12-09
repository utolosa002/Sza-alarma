<?php 
 /*
Funtzio honek erabiltzaile baten sesioa hasten du erregistratua badago lehenagotik.
Erabiltzailearen nick-a, eta pasahitza jaso behar ditu.
Pasahitza eta erabiltzailea ondo sartzen direnenan soilik hasten da sesioa.
Boolearra itzultzen du, baino lehenago script bidez adierazten du.
*/
	function identifikatuErabiltzailea($pErab,$pPass){
		$mota='identifikatu';
		include 'konexioa.inc';
		mysql_select_db($datuBasea,$link);
		$data=getdate();
		$d = $data['mday'];
		$m = $data['mon'];
		$y = $data['year'];
		$query="SELECT * FROM Erabiltzaile WHERE nicka='$pErab'";
		$query1="SELECT * FROM Erabiltzaile WHERE emaila='$pErab'";	
		$query2="UPDATE `Erabiltzaile` SET `azkenkonexioa`='$y-$m-$d' WHERE `nicka`='$pErab' OR `emaila`='$pErab'";
		$emaitza=mysql_query($query,$link);
		if (mysql_num_rows($emaitza)==0) {
	   	$emaitza1=mysql_query($query1,$link);
			if (!$emaitza1) {
				echo "<script type='text/javascript'> alert('Errorea, Ez da aurkitu erabiltzailerik'); window.location='./index.php'; </script>";
				return false;
			}else{
	         	if(mysql_num_rows($emaitza1)==1){
						$erabiltzaileBaimendua = mysql_fetch_array($emaitza1);
						if ($erabiltzaileBaimendua['pasahitza']==sha1($pPass)){
							session_start();
							$emaitza2=mysql_query($query2,$link);
							$_SESSION["erab"]=$pErab;
							return true;
						}else{
							echo "<script type='text/javascript'> alert('Errorea, OkerrekO pasahitza!'); window.location='./index.php';</script>";
							return false;
						}
					}else{
						echo "<script type='text/javascript'> alert('Errorea');  window.location='./index.php';</script>";
						return false;
					}
 			}
		}else{
			if(mysql_num_rows($emaitza)==1){
				$erabiltzaileBaimendua = mysql_fetch_array($emaitza);
				if ($erabiltzaileBaimendua['pasahitza']==sha1($pPass)){
					session_start();
					$emaitza2=mysql_query($query2,$link);
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
		unset($mota);
	}
?>
<?php 
	$erab=$_POST["izena"];
	$pass=$_POST["pasahitza"];
	if(identifikatuErabiltzailea($erab,$pass)) {		
		header("Location: ./erabiltzaile.php");  
	}
?>

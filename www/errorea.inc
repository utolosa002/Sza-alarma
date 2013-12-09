<?php 
	if(isset($_GET['e'])){
		$erroremota=$_GET['e'];
		if($erroremota=="elkar"){
			echo "Elkarbanatzean errorea gertatu da!";
		}else if($erroremota=="erab"){
			echo "Erabiltzaile errorea gertatu da!";
		}else if($erroremota=="sentsore"){
			echo "Sentsore errorea gertatu da!";
		}else if($erroremota=="segoera"){
			echo "Sentsore egoera aldatzean errorea gertatu da!";
		}else if($erroremota=="sezaba"){
			echo "Sentsorea ezabatzean errorea gertatu da!";
		}else if($erroremota=="sgehi"){
			echo "Sentsorea alarmari gehitzean errorea gertatu da!";
		}else if($erroremota=="salarma"){
			echo "Alarma sortzean errorea gertatu da!";
		}else if($erroremota=="alarma"){
			echo "Alarma errorea gertatu da!";
		}else if($erroremota=="aaldatu"){
			echo "Alarma egoera aldatzean errorea gertatu da!";
		}else if($erroremota=="ajabea"){
			echo "Alarmaren jabea izan behar duzu ezabatzeko!";
		}else if($erroremota=="aezabatu"){
			echo "Alarma ezabatzean errorea gertatu da!";
		}else if($erroremota=="konexio"){
			echo "Konexio errorea gertatu da!";
		}else{
			echo "Errorea gertatu da!";
		}
	}else{
		echo "Errorea gertatu da!";
	}
?>

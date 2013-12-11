<?php
/*
Funtzio honek uneko erabiltzailearen alarmak itzultzen ditu array batean 
(false hutsa bada).
*/
	function lortuZureAlarmak()
	{
		include 'konexioa.inc';
		mysql_select_db($datuBasea,$link);
		$erabil=$_SESSION["erab"];
		$query="SELECT `ea`.`idalarma` FROM `Erabiltzaile` AS `e` INNER JOIN `Erab_alarma` AS `ea` WHERE `ea`.`iderab` = `e`.`iderab` AND ( `e`.`emaila` =\"$erabil\" OR `e`.`nicka` = \"$erabil\")";
 		$Alarmak=mysql_query($query,$link);
		 if(mysql_num_rows($Alarmak)==false){
			return false;
		}else{
			while($alarma= mysql_fetch_assoc($Alarmak)){
 				 $AlarmaArray[] = $alarma;
			}
		}
		return $AlarmaArray;
	}

/*
Funtzio honek alarmaren izena lortzen du (false hutsa bada).
Alarmaren ida pasa behar zaio.
*/
	function lortuAlarmarenIzena($Aid)
	{
		include 'konexioa.inc';
		mysql_select_db($datuBasea,$link);
		$query="SELECT `a`.`aizena` FROM `Alarma` AS `a` WHERE `idalarma`=\"$Aid\"";
		$Izena=mysql_query($query,$link);
 		if(mysql_num_rows($Izena)==false){
			return false;
		}else{
			$izen = mysql_fetch_row($Izena);
		}
		return $izen[0];
	}

/*
Funtzio honek alarmaren sentsoreak lortzen ditu (false hutsa bada).
Alarmaren ida pasa behar zaio.
*/
	function lortuAlarmarenSentsoreak($paId)
	{
		include 'konexioa.inc';
		mysql_select_db($datuBasea,$link);
		$query="SELECT `s`.`sid`, `s`.`sizena` ,`s`.`segoera` FROM `Sentsore` AS `s` INNER JOIN `Alarma` AS `a` ON `s`.`idalarma`= `a`.`idalarma` WHERE `a`.`idalarma`=\"$paId\"";
		$Alarmak=mysql_query($query,$link);
 		if(mysql_num_rows($Alarmak)==false){
			return false;
		}else{
			while($alarma= mysql_fetch_assoc($Alarmak)){
 				$AlarmaArray[] = $alarma;
			}
		}
		return $AlarmaArray;
	}
?>

<div class="entry">
	<h1>Sentsore guztiak alarmaz alarma</h1>
	<?php 
		$Alarmak=lortuZureAlarmak();
		if($Alarmak==false){
			echo "<h3>Ez duzu alarmarik </h3>";
		}else{
			$i=0;
			$j=0;
			$k=0;
			foreach ($Alarmak as $Alarma){
				$i++;
				foreach ($Alarma as $AKDatuak) {
					$Sentsoreak=lortuAlarmarenSentsoreak($AKDatuak);
					$izena=lortuAlarmarenIzena($AKDatuak);
					echo "<h2> $izena alarmako sentsoreak </h2>";
					echo "<form id=\"zureAlarmak$i\" action=\"sentsAldatu.php\" method=\"post\">";
	?>			
		<fieldset>
			<table class="table table-stripedtable-condensed">
				<tr>
					<td><h3> Zenb </h3></td>
					<td><h3> Izena </h3></td>	
					<td><h3> Egoera </h3></td>
					<td><h3> Hautatu </h3></td>
				</tr>	
		<?php
			if ($Sentsoreak==false){
				echo "<tr><td> ez duzu sentsorerik</td>\n</tr>\n";
			}else{
				foreach ($Sentsoreak as $sentsore) {
					$lerroa="";
				$k=0;
				$j++;
				foreach ($sentsore as $SDatuak) {
					$k++;
					if($k % 3===0){
						if($SDatuak==="0"){
							$lerroa="<tr class=\"error\">\n".$lerroa."<td><input class=\"uneditable-input\" type=\"text\" id=\"sen$j$k\" name=\"sen$j$k\" readonly=\"readonly\" value= \"Desaktibatuta\" /></td>\n";
						}else{
							$lerroa="<tr class=\"success \">\n".$lerroa."<td><input class=\"uneditable-input\" type=\"text\" id=\"sen$j$k\" name=\"sen$j$k\" readonly=\"readonly\" value= \"Aktibatuta\" /></td>\n";
						}
					}else{
						if(($k+2) % 3===0){
							$j=$SDatuak;
							$lerroa=$lerroa."<td><input class=\"uneditable-input input-mini\" type=\"text\" id=\"sen$j$k\" name=\"sen$j$k\" readonly=\"readonly\" value= \"$SDatuak\" /></td>\n";
						}else{
							$lerroa=$lerroa."<td><input class=\"uneditable-input\" type=\"text\" id=\"sen$j$k\" name=\"sen$j$k\" readonly=\"readonly\" value= \"$SDatuak\" /></td>\n";
						}
					}	
				}	
				echo $lerroa."<td><input type=\"radio\" name=\"hautatu\" value=\"$j\"/></td>\n</tr>\n";
			}
		}
	?>
			</table>
			<button type="submit" class="btn btn-primary btn-large" name="sAldatu" >Sentsore egoera aldatu</button>
			<button type="submit" class="btn btn-primary btn-large" name="sEzabatu" >Sentsorea Ezabatu</button>
		</fieldset>
	</form>
	<?php			
				}
			}
		}
	?>
</div>

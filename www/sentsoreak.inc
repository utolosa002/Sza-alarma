<?php include 'access.inc' ?>  
<?php
	function lortuZureAlarmak()
	{
		include 'konexioa.inc';
		mysql_select_db($datuBasea,$link);
		$erabil=$_SESSION["erab"];
		$query="SELECT `ea`.`alarma` FROM `erabiltzaile` AS `e` INNER JOIN `erab_alarma` AS `ea` WHERE `ea`.`iderab` = `e`.`iderab` AND ( `e`.`emaila` =\"$erabil\" OR `e`.`nicka` = \"$erabil\")";
 		$Alarmak=mysql_query($query,$link);
		 if(mysql_num_rows($Alarmak)==0){
			echo "<script type='text/javascript'> alert('Hutsa Dago, Oraindik ez duzu alarmarik sortu.'); </script>";
			return false;
		}else{
			while($alarma= mysql_fetch_assoc($Alarmak)){
 				 $AlarmaArray[] = $alarma;
			}
		}
		return $AlarmaArray;
	}

	function lortuAlarmarenSentsoreak($AKDatuak)
	{
		include 'konexioa.inc';
		mysql_select_db($datuBasea,$link);
		$query="select `s`.`Sid`, `s`.`Sizena` ,`s`.`Segoera` from `Sentsore` as `s` inner join `Alarma` as `a` on `s`.`Jalarma`= `a`.`alarmaid` where `alarmaid`=\"$AKDatuak\"";
		$Alarmak=mysql_query($query,$link);
 		if(mysql_num_rows($Alarmak)==0){
			echo "<script type='text/javascript'> alert('Hutsa Dago, Oraindik ez duzu alarmarik.'); </script>";
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
		$i=0;
		$j=0;
		$k=0;
		foreach ($Alarmak as $Alarma){
			$i++;
			echo "<h2> $i alarmako sentsoreak </h2>";
			echo "<form id=\"zureAlarmak$i\" action=\"sents_aldatu.php\" method=\"post\">";
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
			foreach ($Alarma as $AKDatuak) {
				$Sentsoreak=lortuAlarmarenSentsoreak($AKDatuak);
				foreach ($Sentsoreak as $sentsore) {
					$lerroa="";
					$k=0;
					$j++;
					foreach ($sentsore as $SDatuak) {
						$k++;
						if($k % 3===0){
							if($SDatuak==="0"){
								$lerroa="<tr class=\"error\">\n".$lerroa."<td><input type=\"text\" id=\"sen$j$k\" name=\"sen$j$k\" readonly=\"readonly\" value= \"Desaktibatuta\" /></td>\n";

							}else{
								$lerroa="<tr class=\"success\">\n".$lerroa."<td><input type=\"text\" id=\"sen$j$k\" name=\"sen$j$k\" readonly=\"readonly\" value= \"Aktibatuta\" /></td>\n";
							}
						}else{
							if(($k+2) % 3===0){
								$j=$SDatuak;
							}
							$lerroa=$lerroa."<td><input type=\"text\" id=\"sen$j$k\" name=\"sen$j$k\" readonly=\"readonly\" value= \"$SDatuak\" /></td>\n";
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
?>
</div>

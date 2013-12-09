<?php include 'access.inc' ?>  
<?php
/*
Funtzio honek alarmaren sentsoreak itzultzen ditu array batean (false hutsa bada).
alarmaren ida pasa behar zaio.
*/
	function lortuAlarmarenSentsoreak($Aid)
	{
		include 'konexioa.inc';
		mysql_select_db($datuBasea,$link);
		$query="SELECT `s`.`sid`, `s`.`sizena` ,`s`.`segoera` FROM `Sentsore` AS `s` INNER JOIN `Alarma` AS `a` ON `s`.`idalarma`= `a`.`idalarma` WHERE `a`.`idalarma`=\"$Aid\"";
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
Funtzio honek alarmaren izena lortzen du (false errorerik bada).
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
?>
<div class="entry">
	<?php 
		if(isset($_GET['al'])) {
		$id=$_GET['al'];
		$j=0;
		$k=0;
		$Sentsoreak=lortuAlarmarenSentsoreak($id);
		$aizena=lortuAlarmarenIzena($id);
		echo "<h2> $aizena alarmako sentsoreak </h2>";
		if ($Sentsoreak==false){
			echo "<table class=\"table table-stripedtable-condensed\"><tr><td> ez du sentsorerik</td>\n</tr>\n</table>";
		}else{
			echo "<form id=\"zureAlarmak$id\" action=\"sents_aldatu.php\" method=\"post\">";
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
			foreach ($Sentsoreak as $sentsore){
				$lerroa="";
				$k=0;
				$j++;
				foreach ($sentsore as $SDatuak){
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

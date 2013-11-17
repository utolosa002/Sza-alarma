<?php 
	function lortuAlarmarenSentsoreak($Aid){
		include 'konexioa.inc';
		mysql_select_db($datuBasea,$link);
		$query="select `s`.`Sid`, `s`.`Sizena` ,`s`.`Segoera` from `Sentsore` as `s` inner join `Alarma` as `a` on `s`.`Jalarma`= `a`.`alarmaid` where `alarmaid`=\"$Aid\"";
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

	if(isset($_GET['sen'])){
		$pId=$_GET['sen'];
	}
?>
<form id="senberria" class="form-signin" enctype="multipart/form-data" action="erabiltzaile.php?sen_berria"  method="post">
	<fieldset id="fi">
<input value="<?php echo $pId;?>" type="hidden" name="aid" id="aid"></input>
		<input type="button" id="addbutton" class="btn btn-large btn-primary" onclick="gehitusents()" value="+ sents"></input>
		<input type="button" id="subbutton" class="btn btn-large btn-primary" onclick="kendusents()" value="- sents" disabled="disabled"></input>
		<button type="submit" class="btn btn-large btn-primary">Gehitu sentsorea</button>
		<?php echo "<h4 class=\"kursiba\">Gehitu sentsorea $pId alarmari</h4>";?>
		</br>
	</fieldset>
</form>

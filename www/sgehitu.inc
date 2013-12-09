<?php include_once 'access.inc' ?>
<?php 
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

<?php include_once 'access.inc' ?>
<form id="Aberria" class="form-signin" enctype="multipart/form-data" action="erabiltzaile.php?alarma_berria" method='POST'>
	<fieldset id="fi">
		<input type="button" id="addbutton" class="btn btn-large btn-primary" onclick="gehitusents()" value="+ sents"></input>
		<input type="button" id="subbutton" class="btn btn-large btn-primary" onclick="kendusents()" value="- sents" disabled="disabled"></input>
		<button type="submit" class="btn btn-large btn-primary">Alarma sortu</button>
		<h4 class="kursiba">Sortu alarma berria</h4>
<input type="text" class="input-large" id="Aizena" name="Aizena" onfocus="kendubalioa(this)" onblur="emanbalioa(this,'Alarma izena')" value="Alarma izena"></input>
		<input type="checkbox" name="egoera" value="egoera" checked="checked"></input>
		</br>
 	</fieldset>
</form>

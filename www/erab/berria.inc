<form id="Aberria" class="form-signin" action="erabiltzaile.php?alarma_berria" method="post">
	<fieldset id="fi">
		<input type="button" id="addbutton" class="btn btn-large btn-primary" onclick="gehitusents()" value="+ sents"></input>
		<input type="button" id="subbutton" class="btn btn-large btn-primary" onclick="kendusents()" value="- sents" disabled="disabled"></input>
		<button type="submit" class="btn btn-large btn-primary">Alarma sortu</button>
		<h4 class="kursiba">Sortu alarma berria</h4>
		<input type="text" class="input-large" id="Aizena" name="Aizena" onfocus="kendubalioa(this)" onblur="emanbalioa(this,'Alarma izena')" value="Alarma izena"></input>
		<input type="checkbox" name="egoera" value="aktibatuta"></input>
		<br/>
 	</fieldset>
</form>

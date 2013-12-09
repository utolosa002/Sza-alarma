function balioztatu(f)
{
	var izena= f.Eizena.value;
	var emaila =f.EEmaila.value;
	var pasahitza= f.Epasahitza.value;
	if(izena==""|| emaila==""||pasahitza==""||izena==" "|| emaila==" "||pasahitza==" ")
	{
		alert("zeoze hutsa da");
		return false;
	}else{
		return emailaDa(emaila);
	}
}

function kendubalioa(f)
{
	if(f.value=="izena"||f.value=="pasahitza"||f.value=="emaila"||f.value=="Erabiltzailea"||f.value=="Alarma izena"){
		f.value="";
	}
}
function emanbalioa(f,str)
{
	if(f.value==""){
		f.value=str;
	}
}

function emailaDa(str)
{
	// Ziurtatu '@' karakterea behin, eta behin bakarrik, agertzen dela.
	if(str.split("@").length != 2)
		return false;
	// Ziurtatu '@' karakterea ez dela lehena.
	if(str.indexOf("@") == 0)
		return false;
	// Ziurtatu '@' karakterearen ondoren '.' karaktereren bat badagoela.
	if(str.lastIndexOf(".") < str.lastIndexOf("@"))
		return false;
	// Ziurtatu azkeneko puntuaren atzetik gutxienez beste 2 karaktere daudela.
	if(str.lastIndexOf(".") + 2 > str.length - 1)
		return false;
	return true;
}



function gehitusents()
{
	document.getElementById("subbutton").disabled = false;
	var diva = document.getElementById("fi");
	var zenb = document.getElementsByName('sizena[]').length+1;
	var inputberria = document.createElement('input');
	inputberria.innerHTML = "<input type=\"text\" class=\"input-large\" id=\"s"+zenb+"\" name=\"sizena[]\" placeholder=\"sentsore izena\" required=\"required\"/>";
	diva.appendChild(inputberria.firstChild);
}

function kendusents()
{	
	var diva = document.getElementById("fi");
	var zenb = document.getElementsByName("sizena[]").length;
	if ((zenb-1)==0){
		document.getElementById("subbutton").disabled = true;
	}
	var szenb= "s"+zenb;
  	var olddiv = document.getElementById(szenb);
	diva.removeChild(olddiv);
}

function AtzeaGorri(elementua)
{
  document.getElementById(elementua).style.background = "red";
  document.getElementById(elementua).style.color = "Black";
}
function AtzeaTxuri(elementua)
{
  document.getElementById(elementua).style.background = "white";
  document.getElementById(elementua).style.color = "Black";
}
function checkAkti()
{

  document.getElementById("publikatu").disabled = false;
}

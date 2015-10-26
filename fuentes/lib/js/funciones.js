//Archivo de funciones para la aplicación web de Barcos

//AJAX
function ajax(){
	if (window.XMLHttpRequest)
		return new XMLHttpRequest();
	else if(window.ActiveXObject)
		return new ActiveXObject("Microsoft.XMLHTTP");
	else return false;	
}

//Caracteres válidos
var letrasMayus = "ABCDEFGHIJKLMNÑOPQRSTUVWXYZÁÉÍÓÚÜ ";
var letrasMinus = letrasMayus.toLowerCase();
var letrasDNI = "TRWAGMYFPDXBNJZSQVHLCKE";
var letrasDNIminus = letrasDNI.toLowerCase();
var numbers = "0123456789";
var guiones = "-_"
var raros = "'@ªº";
var email = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789@._";
var tildesMayus = "ÀÈÙÒÙÂÊÎÔÛÄËÏÖÇ";
var tildesMinus = tildesMayus.toLowerCase();
var signos = ",.;:¡!¿?";
var beta= "β";

//Función que filtra el contenido de una cadena
function filtroTeclado( evento, campo ) {
	var keyNum = ( window.event ? evento.keyCode : evento.which );
	if(navigator.userAgent.indexOf("Firefox") != -1)
		keyNum = evento.keyCode;
	var keyChar;
	var chkValid = '';
	switch (campo)
	{
		//Llamada desde login.php
		case 0: chkValid=letrasMayus+letrasMinus+tildesMayus+tildesMinus+signos+guiones;
					break;
		case 1: chkValid=letrasMayus+letrasMinus+tildesMayus+tildesMinus+signos+numbers;
					break; 	
		//Llamada desde registro.php
		case 2: chkValid=letrasMayus+letrasMinus+tildesMayus+tildesMinus+signos+guiones;
					break;
		case 3: chkValid=letrasMayus+letrasMinus+tildesMayus+tildesMinus+signos+numbers;
					break; 			
		case 4: chkValid=letrasMayus+letrasMinus+tildesMayus+tildesMinus+signos+numbers+guiones+raros+beta;
					break;	
		case 5: chkValid=email;
					break;	
		case 6: chkValid=letrasDNI+letrasDNIminus;
					break;
		case 7: chkValid=numbers;
					break;
	};
	//chkvalid = chkvalid+"\t";
	if ( keyNum == 13 ) {
		var boton = document.getElementById("btnSend");
		boton.click();
	}
	
	if ( keyNum == 9 || keyNum == 8 || keyNum == 46 ||
		( keyNum >= 16 && keyNum <= 18 ) || 
		( keyNum >= 37 && keyNum <= 40 ) ) return true;
	else {
		if(navigator.userAgent.indexOf("Firefox") != -1)
			keyNum = evento.which;
		keyChar = String.fromCharCode(keyNum);
		return chkValid.indexOf(keyChar) != -1;
	}
}	
	
//Abre ventana modal	
function abrir(claro,oscuro) {
	document.getElementById(claro).style.display='block';
	document.getElementById(oscuro).style.display='block';		
}

//Cierra ventana modal
function cerrar(claro,oscuro) {
	document.getElementById(claro).style.display='none';
	document.getElementById(oscuro).style.display='none';		
}

//Devuelve el valor en texto del campo
function getValue(campo) {
	return document.getElementById(campo).value;
}

//Envía registro
function enviaForm() {
	if(checkForm()) {
		formulario=new ajax();
		challenge=Recaptcha.get_challenge();
		response=Recaptcha.get_response();
		envio="nombre="+getValue('regNombre')+
					"&apellido1="+getValue('regApellido1')+
					"&apellido2="+getValue('regApellido2')+
					"&mail="+getValue('regMail')+
					"&dni="+getValue('regDNI')+getValue('regLetraDNI')+
					"&evento="+getValue('lstEvento')+
					"&recaptcha_challenge_field="+challenge+
					"&recaptcha_response_field="+response;
		formulario.open("POST","registro.php",true);
		formulario.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
		formulario.send(envio);
		formulario.onreadystatechange = function() {
			var item=document.getElementById('registro');
			item.innerHTML=formulario.responseText+"<br>";				
		}
		limpiaRegistro();			
		//cerrar('registro','main');
	}
	else alert("Asegúrese de rellenar correctamente todos los campos y sobre todo... ¡Debe leer y aceptar la Ley Orgánica de Protección de Datos!");
}		

//Devuelve si la cadena introducida cumple el tamaño mínimo en cada caso
function esCorrecto(cadena) {
	var numChar=1;
	if(cadena=="regMail") {
		cadena=document.getElementById(cadena).value;
		return checkMail(cadena);
	}
	else if (cadena=="regDNI" || cadena=="regLetraDNI") {
			var dni=document.getElementById("regDNI").value;
			var letra=document.getElementById("regLetraDNI").value.toUpperCase();
			return checkDNI(dni,letra);
	}
	cadena=document.getElementById(cadena).value;
	if(cadena.length<numChar) return false;
	return true;
}

//Comprueba si el DNI coincide con la letra proporcionada y por tanto es un DNI válido
function checkDNI(dni,letra) {
	var letraReal = letrasDNI.charAt(dni % 23);
	if (letra == letraReal)	return true;
	else return false;
}

//Cambia imagen ok o cross si los datos del campo activo son correctos
function putOK(imagen,texto) {
	imagen=document.getElementById(imagen);
	if(esCorrecto(texto)) {
		imagen.src="./images/ok_icon.png";
		return true;
	}
	else {
		imagen.src="./images/cross-icon.png";
		return false;
	}
}

//Comprueba la dirección de correo
function checkMail(mail) {
	expresion=/^[_a-z0-9-]+(.[_a-z0-9-]+)*@[a-z0-9-]+(.[a-z0-9-]+)*(.[a-z]{2,3})$/;
	if(!expresion.exec(mail))	return false;
	else	return true;
}

//Comprueba el formulario completo antes de mandarlo
function checkForm() {
	var valido=true;
	if(!putOK('imgApellido1','regApellido1')) valido=false;
	if(!putOK('imgApellido2','regApellido2')) valido=false;
	if(!putOK('imgNombre','regNombre')) valido=false;
	if(!putOK('imgDNI','regDNI')) valido=false;
	if(!putOK('imgDNI','regLetraDNI')) valido=false;
	if(!putOK('imgMail','regMail')) valido=false;
	if(!document.getElementById("btnLopd").checked) valido=false;
	if(!Recaptcha.get_response()) valido=false;
	return valido;
}

//Inicializa hoja de registro
function limpiaRegistro() {
	limpiar('regApellido1');
	limpiar('regApellido2');
	limpiar('regNombre');
	limpiar('regDNI');
	limpiar('regLetraDNI');
	limpiar('regMail');
	limpiarImg('imgApellido1');
	limpiarImg('imgNombre');
	limpiarImg('imgApellido2');
	limpiarImg('imgMail');
	limpiarImg('imgDNI');
	Recaptcha.reload();
	document.getElementById('btnLopd').checked = false;
}

//Inicializa los campos del registro
function limpiar(campo) {
	return document.getElementById(campo).value='';
}

//Inicializa las imágenes del registro
function limpiarImg(campo) {
	return document.getElementById(campo).src='images/Blank.png';
}

function enviaEvento() {
		formulario=new ajax();
		envio="source_event=Prueba";
		formulario.open("POST","registro.php",true);
		formulario.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
		formulario.send(envio);
		formulario.onreadystatechange = function() {
			var item=document.getElementById('mensaje');
			item.innerHTML=formulario.responseText+"<br>";	
		}
}
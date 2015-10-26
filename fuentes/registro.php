<?php

require_once('./lib/php/recaptchalib.php');
require_once('./lib/php/sendmail.php');
$publickey = "6Lezo84SAAAAAK9O-cgYF9sh-Gc4adwj_Mj2o86e"; 
$privatekey = "6Lezo84SAAAAAJrxmlCqpKlgypEjt7aMNQuJtiZE";

if(!isset($_POST['nombre']) || !isset($_POST['apellido1']) || !isset($_POST['apellido2']) || !isset($_POST['dni']) || !isset($_POST['mail']) || !isset($_POST['evento'])) {
?>		
<div id="registro" align="center">
<h2>Reserva de plaza en el evento</h2>
<table align="center">
	<tr>
		<td>Nombre:</td>
		<td><input type="text" id="regNombre" name="regNombre" size="30" maxlength=40 onkeypress="return filtroTeclado(event,2);" onblur="putOK('imgNombre','regNombre');"/><img id="imgNombre" class="icono" src="images/Blank.png" /></td>
	</tr>
	<tr>
		<td>Primer apellido:</td>
		<td><input type="text" id="regApellido1" name="regApellido1" size="30" maxlength=40 onkeypress="return filtroTeclado(event,2);" onblur="putOK('imgApellido1','regApellido1');"/><img id="imgApellido1" class="icono" src="images/Blank.png" /></td>
	</tr>
	<tr>
		<td>Segundo apellido:</td>
		<td><input type="text" id="regApellido2" name="regApellido2" size="30" maxlength=40 onkeypress="return filtroTeclado(event,2);" onblur="putOK('imgApellido2','regApellido2');"/><img id="imgApellido2" class="icono" src="images/Blank.png" /></td>
	</tr>
	<tr>
		<td>Correo electrónico:</td>
		<td><input type="text" id="regMail" name="regMail" size="50" maxlength=100 onkeypress="return filtroTeclado(event,5);"onblur="putOK('imgMail','regMail'); "/><img id="imgMail" class="icono" src="images/Blank.png" /></td>
	</tr>
	<tr>
		<td>DNI:</td>
		<td><input type="text" id="regDNI" name="regDNI" size="10" maxlength=8 onkeypress="return filtroTeclado(event,7);" onblur="putOK('imgDNI','regDNI');"/>
		<input type="text" id="regLetraDNI" name="regLetraDNI" size="2" maxlength=1 onkeypress="return filtroTeclado(event,6);" onblur="putOK('imgDNI','regLetraDNI');"/><img id="imgDNI" class="icono" src="images/Blank.png" /></td>
	</tr>
	<?php if(!isset($_POST['source_event'])) { ?>
	<tr>
		<td>Evento:</td>
		<td><select id="lstEvento" name="lstEvento">
	<?php
		$db=db_connect();
		$select="select IDEvento,Nombre from Evento";
		if($doQuery=mysqli_query($db,$select)) {
			while($listEventos = mysqli_fetch_assoc($doQuery)) { 
				echo '<option value="'.$listEventos['IDEvento'].'">'.utf8_encode($listEventos['Nombre']).'</option>';
			};
			mysqli_free_result($listEventos);
			mysqli_close();
		}
		else echo '<option>No se encontraron eventos</option>';
	?>
	</select></td>
	</tr>
	<?php } else { ?>
	<h3> <?php echo $_POST['source_event']; }?></h3>
</table>
<br>
<div id="captcha"> <?php echo recaptcha_get_html($publickey);?></div>
<br>
<div class="lopd" align="justify">
En conformidad con lo previsto en la <a href="https://www.agpd.es/portalwebAGPD/canaldocumentacion/legislacion/estatal/common/pdfs/Ley-15_99.pdf">Ley Orgánica 15/1999, del 13 de diciembre, de Protección de Datos de Carácter Personal (LOPD)</a>,
se le informa de la existencia de un registro en la base de datos de su titularidad en el cual se incluirán los datos necesarios para proporcionar los servicios que los usuarios soliciten.<br>
El titular podrá ejercitar los derechos reconocidos en la LOPD sobre este fichero y, en particular, los de acceso, rectificación o cancelación de datos y oposición, si resultara pertinente, así como el de revocación del consentimiento para la cesión de sus datos en los términos previstos en la LOPD. Los usuarios pueden realizar estas acciones enviando una solicitud al
administrador de este sitio web. 
</div>
<input id="btnLopd" name="btnLopd" type="checkbox">He leído y acepto la LOPD</input>
<br><div id="mensaje"></div><br>
<button id="btnSend" name="btnSend" type="submit" onmouseover="checkForm();" onclick="enviaForm();">Enviar</button>
<button name="btnClose" type="button" onclick="cerrar('registro','main');limpiaRegistro();">Cancelar</button>
</div>
<?php }
else {
if(isset($_POST["recaptcha_challenge_field"]) && isset($_POST["recaptcha_response_field"])) {
	$resp=recaptcha_check_answer($privatekey,
										$_SERVER["REMOTE_ADDR"],
										$_POST["recaptcha_challenge_field"],
										$_POST["recaptcha_response_field"]);
	if ($resp->is_valid)
	{ 
		include_once('./lib/db/db_connect.php.inc');

		$nombre=utf8_decode($_POST['nombre']);
		$apellido1=utf8_decode($_POST['apellido1']);
		$apellido2=utf8_decode($_POST['apellido2']);
		$mail=$_POST['mail'];
		$dni=$_POST['dni'];
		$evento=$_POST['evento'];
		$md5=md5($dni.$mail.$evento);

		$db=db_connect();
		$aforo=mysqli_fetch_array(mysqli_query($db,"select count(*) from ListaVisitantes where IDEvento='".$evento."' and Activo=1;"));
		$maxaforo=mysqli_fetch_array(mysqli_query($db,"select Aforo from Evento where IDEvento='".$evento."';"));
		if($aforo<$maxaforo){
			//Comprobamos si se ha registrado en otro evento previamente, para no volverlo a crear en la tabla de Visitante
			$select="select * from Visitante inner join ListaVisitantes on ListaVisitantes.IDEvento=".$evento." where (DNI like '".$dni."' or Email like '".$mail."') and Visitante.IDVisitante=ListaVisitantes.IDVisitante;)";
			if(mysqli_num_rows(mysqli_query($db,$select))<1) {
				//Comprobamos que no existe el DNI en Visitante
				$select="select DNI from Visitante inner join ListaVisitantes on ListaVisitantes.IDEvento=".$evento." where DNI like '".$dni."' and Visitante.IDVisitante=ListaVisitantes.IDVisitante;";
				if(mysqli_num_rows(mysqli_query($db,$select))<1) {
					//Comprobamos que no existe la dirección de correo en Visitante
					$select="select Email from Visitante inner join ListaVisitantes on ListaVisitantes.IDEvento=".$evento." where Email like '".$mail."' and Visitante.IDVisitante=ListaVisitantes.IDVisitante;";
					if(mysqli_num_rows(mysqli_query($db,$select))<1) {
						//Comprobamos que el visitante no está ya registrado en el evento seleccionado, para ello guardamos el IDVisitante de la tabla Visitante
						$select="select IDVisitante from Visitante where DNI like '".$dni."' or Email like '".$mail."'";
						$id=mysqli_fetch_row(mysqli_query($db,$select));			
						$id=$id[0];
						//Buscamos el evento que coincida con el Visitante cuya IDVisitante es $id
						$select="select IDEvento,IDVisitante from ListaVisitantes where IDEvento like '".$evento."' and IDVisitante like '".$id."'";
						if(mysqli_num_rows(mysqli_query($db,$select))<1) {
							if(sendmail($mail,$md5)) {
								echo "Se ha registrado correctamente en el evento. Revise su correo y confirme su asistencia antes de que pasen 24 horas.";
								$select="select * from Visitante where DNI like '".$dni."' or Email like '".$mail."';";
								if(mysqli_num_rows(mysqli_query($db,$select))<1) {
									//Insertamos al Visitante en la tabla ya que ni su dni ni su correo existen, y puede haber individuos con el mismo nombre pero son distintas personas
									$insertar="insert into Visitante(Nombre,Apellido1,Apellido2,DNI,Email)
											values ('".$nombre."','".$apellido1."','".$apellido2."','".$dni."','".$mail."')";
									mysqli_query($db,$insertar);
								}
								$select="select IDVisitante from Visitante where DNI like '".$dni."'";
								$id=mysqli_fetch_array(mysqli_query($db,$select));
								//Registramos efectivamente al Visitante en el Evento, es decir, lo insertamos en ListaVisitantes
								$insertar="insert into ListaVisitantes(IDEvento,IDVisitante) values ('".$evento."','".$id[0]."')";
								mysqli_query($db,$insertar);
								$insertar="insert into ValidaReserva(IDVisitante,IDEvento,MD5,Fin)
										values ('".$id[0]."','".$evento."','".$md5."',NOW()+INTERVAL 1 DAY)";
								mysqli_query($db,$insertar);
							}
							else 
								echo "No se pudo enviar el correo de validación, por lo que no se ha realizado la reserva correctamente. Inténtelo de nuevo.";					
						}
						else echo "Usted está ya registrado en este evento, revise su correo para más información.";
					}
					else echo "La dirección de correo electrónico proporcionada está ya registrada. Compruebe sus datos.";
				}
				else echo "El DNI proporcionado está ya registrado. Compruebe sus datos.";
			}
			else echo "Está registrado en nuestra base de datos con otro nombre y apellidos. Compruebe sus datos.";
		}
		else
			echo "Lo sentimos pero no puede reservar plaza en el evento, ya está completo.";		
		mysqli_close($db);
	}
	else echo "Captcha inválido. Vuelva a intentar el registro.";
}
}
?>
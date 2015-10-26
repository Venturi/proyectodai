<?php
function sendmail($mail,$md5) {
	require_once('./lib/php/swift_required.php');	
	
	$server="localhost/regevent"; //Editar con la url del servidor donde se aloje finalmente la aplicación
	$transport = Swift_SmtpTransport::newInstance('smtp.gmail.com', 465, 'ssl')
		->setUsername('vcongressman')
		->setPassword('vcongressman1900');
	$mailer = Swift_Mailer::newInstance($transport);
	$subject="Validación del registro en el evento";
	$body="Para confirmar su asistencia al evento, pulse en el siguiente enlace:\n http://".$server."/validacion.php?validacion=".$md5;
	$message = Swift_Message::newInstance()
		->setSubject($subject)
		->setFrom(array('vcongressman@venturisoft.com' => 'Venturi Congress Man'))
		->addTo($mail)
		->setBody($body);
	return $mailer->send($message);
}
?>
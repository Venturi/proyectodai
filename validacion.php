<?php

include_once('./lib/db/db_connect.php.inc');

if(!isset($_GET['validacion']))
	echo "Error en el enlace de validación. Inténtelo de nuevo. Disculpe las molestias.";
else {
	$db=db_Connect();
	$md5=$_GET['validacion'];
	//Busca el md5 recibido en la base de datos
	$md5_valido=mysqli_query($db,"select * from ValidaReserva where MD5 like '".$md5."'");
	//Recoge el resultado de la búsqueda y lo guarda en una array
	if(!$resultado=mysqli_fetch_array($md5_valido))
		echo "No se ha encontrado la reserva en la base de datos";
	else {
		//Almacena los campos IDVisitante e IDEvento de la tabla ListaVisitantes en sendas variables
		$visitanteID=$resultado[0];
		$eventoID=$resultado[1];
		//Busca el ID en la tabla ListaVisitantes que coincide con el IDVisitante y el IDEvento de la tabla ListaVisitantes
		$savedID=mysqli_query($db,"select IDVisitante,IDEvento from ListaVisitantes where IDVisitante='".$visitanteID."' and IDEvento='".$eventoID."'");
			if(!$resultado=mysqli_fetch_array($savedID))
				echo "No se encuentra la reserva registrada en esta base de datos";
			else {
				//Elimina el registro de la tabla ValidarReserva, ya que se ha encontrado y se procede la validación				
				if(mysqli_query($db,"delete from ValidaReserva where MD5 like '".$md5."';")){
					if(mysqli_query($db,"update ListaVisitantes set Activo='1' where IDVisitante='".$visitanteID."' and IDEvento='".$eventoID."'"))
						echo "¡Reserva validada correctamente!";
					else
						echo "No se pudo activar la reserva";
				}
				else
					echo "Ya se realizó la reserva con este código de activación: ".$md5;
			}
		}	
	mysqli_close($db);	
}
?>

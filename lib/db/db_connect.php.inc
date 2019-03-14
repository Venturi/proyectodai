<?php

function db_connect() {
	$res=mysqli_connect('localhost', 'vcmuser', 'vcmuser','vcongressman') or die('Error al conectar con la base de datos');
	return $res;
}

?>
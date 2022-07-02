<?php

$name = $_REQUEST['name'];
$password = $_REQUEST['password'];
$cpassword = $_REQUEST['cpassword'];
$type = $_REQUEST['type'];
$id= $_REQUEST['ID'];
if($name == null || $password == null  ||$id==null){
	echo "INVALID";

}else{
		$user = $name."|".$password."|".$id."|".$type."\r\n";
		$file = fopen('user.txt', 'a');
		fwrite($file, $user);
		if($fname == 'create'){
			header('location: home.php');
		}else{
			header('location: login.html');			
		}

}
?>
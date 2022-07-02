<?php 

$id = $_REQUEST['id'];
$password = $_REQUEST['password'];

if($id == null || $password == null){
	echo "null username/password...";
}else{
	
	$file = fopen('user.txt', 'r');
	
	while (!feof($file)) {
		$data = fgets($file);
		$user = explode("|", $data); 
		if($id == trim($user[2]) && $password == trim($user[1])) {
			setcookie('status', 'true', time()+3600, '/');		
			header('location: home.php?username='.$username);
		}	
	}

	echo "invalid username/password";
}?>
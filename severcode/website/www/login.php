<?php 
    session_start();
    include_once "db_functions.php";
    
    $username = $_POST["username"];
    $password = $_POST["password"];
    $msg = "";

	if ($_SERVER["REQUEST_METHOD"] == "POST") {
		if (empty($username)) {
			$msg = " * Username cannot be empty!";
		}
		else {
			$conn = connectDB();
			$sql = "SELECT * FROM Users WHERE IntlID='$username' AND Password='$password'";
			$result = $conn->query($sql);
			// if match
			if ($result && $result->num_rows > 0) {
				$msg = "Logged in successfully!";
				$_SESSION['curr_user'] = $username; 
				header("location:seats.php");
				exit;
			} else {
				$msg = "Username and Password do not match!";
			}
			$conn->close();
		}
	}
?>


<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0, shrink-to-fit=no">
    <title>SeatU - Login</title>
    <link rel="stylesheet" href="assets/bootstrap/css/bootstrap.min.css">
</head>

<body>
    
    <main class="page login-page" style="padding-top: 30px">
        <section class="clean-block clean-form dark">
            <div class="container">
                <div class="block-heading" style="padding-bottom: 20px">
                    <h2 style="font-family: Ubuntu; color: #52c4be">Welcome to SeatU - Login</h2>
                </div>
                
                <form action="<?php echo $_SERVER['PHP_SELF'];?>" method="POST">
                    <div class="form-group">
                        <label>Username &nbsp; <span class='warning'><?php echo($msg); ?></span> </label>
                        <input class="form-control item" type="text" name="username" value="<?php echo $username;?>">
                    </div>
					
                    <div class="form-group" style="padding-bottom: 30px">
                        <label>Password</label>
                        <input class="form-control" type="password" name="password" value="<?php echo $password;?>">
                    </div>

					<button type="submit" class="btn btn-default btn-block" name="submit" style="background-color: #52c4be; border-color: #52c4be; color: #fff">Log In</button>
					

                </form>
                
            </div>
        </section>
    </main>

    <script src="assets/js/jquery.min.js"></script>
    <script src="assets/bootstrap/js/bootstrap.min.js"></script>
</body>

</html>

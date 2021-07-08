<?php

function connectDB() {
    $servername = "db"; // 'database' for docker server, 127.0.0.1 for MAMP
    $username = "MSCS";
    $password = "ece445";
    $dbname = "SeatU";

    $conn = new mysqli($servername, $username, $password, $dbname);
    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
        return null;
    } 
    return $conn;
}

// preprocess the input from form
function ppc($data) {
    $data = trim($data);
    $data = stripslashes($data);
    $data = htmlspecialchars($data);
    return $data;
}

?>
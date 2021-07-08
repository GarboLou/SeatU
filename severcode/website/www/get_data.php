<?php

/* database infomation */
$servername = "1.116.101.206";
$dbname = "SeatU";
$username = "MSCS";
$password = "ece445";

// DeviceID, TableID, US_Mean, IR_Mean, US_Var, IR_Var
$DeviceID = $TableID = $US_Mean = $IR_Mean = $US_Var = $IR_Var = "";

echo "upload method" . $_SERVER["REQUEST_METHOD"];

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    
    $DeviceID = test_input($_POST["DeviceID"]);
    $TableID = test_input($_POST["TableID"]);
    $US_Mean = test_input($_POST["US_Mean"]);
    $IR_Mean = test_input($_POST["IR_Mean"]);
    $US_Var = test_input($_POST["US_Var"]);
    $IR_Var = test_input($_POST["IR_Var"]);

    // $read_post = file_get_contents('php://input');
    // $datas = json_decode($read_post, true);
    // $DeviceID = $datas["DeviceID"];
    // $TableID = $datas["TableID"];
    // $US_Mean = $datas["US_Mean"];
    // $IR_Mean = $datas["IR_Mean"];
    // $US_Var = $datas["US_Var"];
    // $IR_Var = $datas["IR_Var"];

    echo "data" . $DeviceID . $TableID . "\n";
    
    /* connect to database */
    $conn = new mysqli($servername, $username, $password, $dbname);
    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    } 

    $sql = "UPDATE SensorData 
            SET US_Mean = '$US_Mean', IR_Mean = '$IR_Mean', US_Var = '$US_Var', IR_Var = '$IR_Var'
            WHERE DeviceID = '$DeviceID' AND TableID = '$TableID'";
    // $success = $conn->query($sql);

    if ($conn->query($sql) === TRUE) {
        echo "New record created successfully";
    } 
    else {
        echo "Error: " . $sql . "<br>" . $conn->error;
    }

    $conn->close();

}
else {
    echo "No data posted with HTTP POST.<br/>";
}

function test_input($data) {
    $data = trim($data);
    $data = stripslashes($data);
    $data = htmlspecialchars($data);
    return $data;
}

?>
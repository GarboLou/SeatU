<?php
	include_once "db_functions.php";	
	session_start(); 
    $curr_user = $_SESSION['curr_user'];

    if (!$curr_user) {
        header("location:index.php");
    }
	
    $conn = connectDB();
    
    $sql = "SELECT * FROM Seats";
    $result = $conn->query($sql);
    $array = array();

    $state = array();
    while($row = mysqli_fetch_assoc($result)){
        $array[]=$row;

        // $state[]=$row['State'];

        if ($row['State'] == 0){
            $state[] = "available";
        }elseif ($row['State'] == 1){
            $state[] = "byitems";
        }else{
            $state[] = "bypeople";
        }
    }

    $conn->close();
?>

<script language="JavaScript">
    setTimeout(function(){location.reload()},10000); //指定10秒刷新一次
</script>

<!DOCTYPE html>
<html lang="en">


<head>
    <link rel="stylesheet" href="statecolor.css">
</head>
<div id="labtrack_div" style="text-align: center; font-family: Ubuntu; color: #52c4be">
    <h3 >SeatU: Library Seating Monitoring System</h3>
    <a class="btn btn-primary btn-xl js-scroll-trigger" role="button" href="seats.php"><h4>Planner Version</h4></a>
    <svg xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" class="" app-context="doc-2d" x="0px" y="0px" width="1250" height="1000" id="labtrack">

        <g id="jvs-guides" transform="matrix(1 0 0 1 0 0)"></g>
            <g id="jvs-content" enable-background="new">
                <g transform="matrix(1,0,0,1,0,0)" name="Layer" jvs-layer-color="#fb0094" class="jvs-layer selected">
                <image transform="matrix(1 0 0 1 80 70)" width="200" height="160" href="legend.png" rx="0" y="0" x="0"></image>
                    	<!-- top-top -->
                    	<rect class="<?php echo $state[0]; ?>" id="ZJUINTL-LIB-001" transform="matrix(1 0 0 1 420 60)" width="240" height="156" opacity="1" rx="0" y="0" x="0"></rect>
                    	<rect class="<?php echo $state[3]; ?>" id="ZJUINTL-LIB-002" transform="matrix(1 0 0 1 420 222)" width="240" height="156" opacity="1" rx="0" y="0" x="0"></rect>
                    	<rect class="<?php echo $state[1]; ?>" id="ZJUINTL-LIB-003" transform="matrix(1 0 0 1 666 60)" width="240" height="156" opacity="1" rx="0" y="0" x="0"></rect>
                    	<rect class="<?php echo $state[2]; ?>" id="ZJUINTL-LIB-004" transform="matrix(1 0 0 1 666 222)" width="240" height="156" opacity="1" rx="0" y="0" x="0"></rect>
			<text class="usage-info tooltipstered" fill="#000000" x="440" y="110" font-family="Ubuntu" font-size="45" font-weight="bold">01</text>
			<text class="usage-info tooltipstered" fill="#000000" x="440" y="272" font-family="Ubuntu" font-size="45" font-weight="bold">04</text>	
			<text class="usage-info tooltipstered" fill="#000000" x="686" y="110" font-family="Ubuntu" font-size="45" font-weight="bold">02</text>
               		<text class="usage-info tooltipstered" fill="#000000" x="686" y="272" font-family="Ubuntu" font-size="45" font-weight="bold">03</text>
		</g>
            </g>
        </svg>
    </div>

</html>

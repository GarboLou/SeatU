<?php
    session_start();
    $curr_user = $_SESSION['curr_user'];
?>

<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0, shrink-to-fit=no">
    <title>Home - Login</title>
    <link rel="stylesheet" href="assets/bootstrap/css/bootstrap.min.css">
    <link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Source+Sans+Pro:300,400,700,300italic,400italic,700italic">
    <link rel="stylesheet" href="assets/fonts/font-awesome.min.css">
    <link rel="stylesheet" href="assets/fonts/simple-line-icons.min.css">
</head>

<body id="page-top">

<!-- <a class="menu-toggle rounded" href="#"><i class="fa fa-bars"></i></a>
    <nav class="navbar navbar-light navbar-expand" id="sidebar-wrapper">
        <div class="container"><button data-toggle="collapse" class="navbar-toggler d-none" data-target="#"></button>
            <div class="collapse navbar-collapse">
                <ul class="navbar-nav sidebar-nav" id="sidebar-nav">
                    <li class="nav-item sidebar-brand"><a class="nav-link active js-scroll-trigger" href="#page-top">Home</a></li>
                    <li class="nav-item sidebar-nav-item"><a class="nav-link js-scroll-trigger" href="#page-top">Home</a></li>
                    <li class="nav-item sidebar-nav-item"><a class="nav-link js-scroll-trigger" href="test.html">About</a></li>
                    <li class="nav-item sidebar-nav-item"><a class="nav-link js-scroll-trigger" href="#contact">Contact</a></li>
                </ul>
            </div>
        </div>
    </nav> -->

    <header class="d-flex masthead" style="background-image: url(&quot;assets/img/1533854092569499.jpg&quot;);background-size: cover;background-position: top;">
        <div class="container my-auto text-center" style="height: 400px;padding: 0px 0px;padding-top: 0px;">
            <h1 class="mb-1">Seat U</h1>
            <h3 class="mb-5"><em>INTL Library Seat Availablity</em></h3><a class="btn btn-primary btn-xl js-scroll-trigger" role="button" href="<?php echo $curr_user?'seats.php':'login.php';?>" style="width: 322px;height: 99px;background-color: transparent;background-image: url(&quot;assets/img/微信图片_20210317133639.jpg&quot;);background-position: center;background-size: cover;opacity: 0.86;"></a>
            <!-- <div></div><a class="btn btn-primary btn-xl js-scroll-trigger" role="button" href="#about" style="width: 340px;height: 50px;background-color: transparent;background-image: url(&quot;assets/img/微信图片_20210317133649.jpg&quot;);background-position: center;background-size: cover;opacity: 0.86;"></a> -->
        </div>
    </header>

    <!-- <section id="about" class="content-section bg-light" style="background-image: url(&quot;assets/img/pic_map2f_english20181217.png&quot;);background-size: cover;height: 600px;"></section> -->

    <footer class="footer text-center">
        <div class="container">
            <ul class="list-inline mb-5">
                <li class="list-inline-item">&nbsp;<a class="text-white social-link rounded-circle" href="#"><i class="icon-social-facebook"></i></a></li>
                <li class="list-inline-item">&nbsp;<a class="text-white social-link rounded-circle" href="#"><i class="icon-social-twitter"></i></a></li>
                <li class="list-inline-item">&nbsp;<a class="text-white social-link rounded-circle" href="#"><i class="icon-social-github"></i></a></li>
            </ul>
            <p class="text-muted mb-0 small">Copyright &nbsp;© SeatU 2021</p>
    </footer>
    <script src="assets/js/jquery.min.js"></script>
    <script src="assets/bootstrap/js/bootstrap.min.js"></script>
    <!-- <script src="https://cdnjs.cloudflare.com/ajax/libs/jquery-easing/1.4.1/jquery.easing.min.js"></script> -->
    <script src="assets/js/stylish-portfolio.js"></script>
</body>

</html>
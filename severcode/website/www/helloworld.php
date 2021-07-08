<html>

<body>
<script src="http://libs.baidu.com/jquery/1.10.2/jquery.min.js"></script>
<script type="text/javascript">
function test() {
                var dataToSend = {
                    DeviceID: "1",
                    TableID:"1",
                    US_Mean:"5.4",
                    IR_Mean:"5.4",
                    US_Var:"5.4",
                    IR_Var:"5.4"
                    };
                var jsonDataToSend = JSON.stringify(dataToSend);
                $.ajax({
                    type:'POST',
                    url: "http://1.116.101.206:8001/get_data.php",
                    data: jsonDataToSend,
                    success:function(data){
                        console.log("success");
                    },
                    error: function (data) {
                        console.log("error");
                    }
                });
            }
</script> 
<button onclick="test()">test</button>
</table>
</body>

</html>
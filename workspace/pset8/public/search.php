<?php

    require(__DIR__ . "/../includes/config.php");

    // numerically indexed array of places
    $places = [];

    // TODO: search database for places matching $_GET["geo"], store in $places
    
    if($_SERVER["REQUEST_METHOD"] == "GET")
    {
        //print if $GET[geo] is empty
        if(empty($_GET["geo"]))
        {
            //$_GET["geo"] is empty and is printed
            //echo("There is no location specified in the GET request.");
        }
        //the code in else block splits $_GET["get"] on ',' and retrieves the place name/postal code
        else
        {
            $geo_request = $_GET["geo"];
            $geo_parameters = explode(",", $geo_request);
            //NOTE : the variable $place_name can contain both the name of the place or the postal code.
            $place_name = $geo_parameters[0];
            $places = CS50::query("SELECT * FROM places WHERE MATCH(place_name, postal_code) AGAINST(?)", $place_name);
        }
    }
    

    // output places as JSON (pretty-printed for debugging convenience)
    header("Content-type: application/json");
    print(json_encode($places, JSON_PRETTY_PRINT));

?>
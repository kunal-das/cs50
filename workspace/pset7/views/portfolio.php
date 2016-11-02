<div id="middle">
    <table class="table table-striped">
        <thead>
            <?php
                print("<tr>");
                print("<th>Symbol</th>");
                print("<th id=\"stock-name\">Name</th>");
                print("<th>Shares</th>");
                print("<th>Price</th>");
                print("<th>TOTAL</th>");
                print("</tr>");
            ?>
        </thead> 
        <tbody>
            <?php  
                foreach($holdings as $holding)
                {
                    print("<tr>");
                    print("<td id=\"symbol\">{$holding["symbol"]}</td>");
                    print("<td id=\"stock-name\">{$holding["name"]}</td>");
                    print("<td>{$holding["shares"]}</td>");
                    print("<td>{$holding["price"]}</td>");
                    $total = $holding["shares"]*$holding["price"];
                    print("<td>{$total}</td>");
                    print("</tr>");
                }
                print("<tr>");
                print("<td colspan='4' id=\"symbol\">CASH</td>");
                print("<td>{$cash}</td>");
                print("</tr>");
            ?>
        </tbody>
    </table>
</div>

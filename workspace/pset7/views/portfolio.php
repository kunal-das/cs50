<table class="table table-striped">
    <thead>
        <?php
            print("<tr>");
            print("<th>Symbol</th>");
            print("<th id=\"center-table-heads\">Name</th>");
            print("<th id=\"center-table-heads\">Shares</th>");
            print("<th id=\"center-table-heads\">Price</th>");
            print("<th id=\"center-table-heads\">TOTAL</th>");
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

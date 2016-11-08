<table class="table table-striped">
    <thead>
        <?php
            print("<tr>");
            print("<th>Transaction</th>");
            print("<th id=\"center-table-heads\">Date/Time</th>");
            print("<th id=\"center-table-heads\">Symbol</th>");
            print("<th id=\"center-table-heads\">Shares</th>");
            print("<th id=\"center-table-heads\">Price</th>");
            print("</tr>");
        ?>
    </thead> 
    <tbody>
        <?php  
            foreach($user_history as $row)
            {
                print("<tr>");
                print("<td id=\"transaction-center\">{$row["transaction"]}</td>");
                print("<td>{$row["time"]}</td>");
                print("<td>{$row["symbol"]}</td>");
                print("<td>{$row["shares"]}</td>");
                print("<td>\${$row["price"]}</td>");
                print("</tr>");
            }
        ?>
    </tbody>
</table>

<form action="sell.php" method="post">
    <div class="form-group">
        <table class="table table-striped">
            <thead>
                <?php
                    print("<tr>");
                    print("<th>Symbol</th>");
                    print("<th id=\"center-table-heads\">Name</th>");
                    print("<th id=\"center-table-heads\">Price</th>");
                    print("</tr>");
                ?>
            </thead>
            <tbody>
                <?php
                    $index=0;
                    foreach($holdings as $holding)
                    {
                        print("<tr>");
                        $symbol = $holding["symbol"];
                        print("<td style=\"text-align:left\"><label class=\"checkbox-inline\"><input name=\"symbol[]\" value=\"{$symbol}\" type=\"checkbox\" id=\"{$symbol}\">{$symbol}</label></td>");
                        print("<td>{$holding["name"]}</td>");
                        print("<td>{$holding["price"]}</td>");
                        print("</tr>");
                        $index++;
                    }
                ?>
            </tbody>
        </table>
    </div>
    <div class="form-group">
        <button class = "btn btn-primary" type="submit">
            <span aria-hidden="true" class="glyphicon glyphicon-euro"></span>>
            Sell
        </button>   
    </div>
</form>


def stock_portfolio():
    stock_prices = {
        "AAPL": 180,
        "TSLA": 250,
        "GOOGL": 135,
        "MSFT": 330,
        "AMZN": 140
    }

    n = int(input("Enter number of stocks you own: "))
    total_value = 0
    portfolio = []

    for _ in range(n):
        stock = input("Enter stock symbol (AAPL/TSLA/GOOGL/MSFT/AMZN): ").upper()
        qty = int(input("Enter quantity: "))

        if stock in stock_prices:
            value = stock_prices[stock] * qty
            total_value += value
            portfolio.append(f"{stock} -> {qty} shares = ${value}")
        else:
            print("⚠️ Invalid stock symbol!")

    print("\n📊 Portfolio Summary:")
    for line in portfolio:
        print(line)
    print(f"Total Investment Value: ${total_value}")

    with open("portfolio.txt", "w") as f:
        f.write("Stock Portfolio Summary\n")
        f.write("-----------------------\n")
        for line in portfolio:
            f.write(line + "\n")
        f.write(f"\nTotal Investment Value: ${total_value}\n")

if __name__ == "__main__":
    stock_portfolio()

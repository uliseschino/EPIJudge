from typing import List
import sys

from test_framework import generic_test


def buy_and_sell_stock_once(prices: List[float]) -> float:
    max_gain = 0
    min_so_far = sys.maxsize
    for price in prices:
        gain = price - min_so_far
        max_gain = max(max_gain, gain)
        min_so_far = min(min_so_far, price)
    return max_gain


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('buy_and_sell_stock.py',
                                       'buy_and_sell_stock.tsv',
                                       buy_and_sell_stock_once))

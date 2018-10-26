# Thunder Trader
## Feature
Based on C++ 11, this project implements a quantitative trading system supporting high-frequency transactions. The system supports the following characteristics:
> * Using plug-ins to support different quotations and trading interfaces, such as CTP, Femas, Dfitc and TWS in China.
> * Support multiple accounts and multiple strategies. Each strategy can use multiple quotes, and can place orders for multiple accounts.
> * The real-time tracing of the variables in the policy can be realized by "probe" and the display mode of the data can be customized.
> * Supporting the "intervention" of the strategy, by predefining some intervention actions, to achieve a fixed operation in the transaction process.
> * C/S architecture

And welcome to my [personal blog](http://180.76.118.4/). There are detailed introductory manuals.

> * [Introductory](http://180.76.118.4/HFT-start.html)
> * [Prepare](http://180.76.118.4/HFT-prepare.html)
## Quit start
This preject is tested in following environment:
> * gcc 7.2
> * boost 1.68.0
> * centos7

Usage:
```
>cmake .
>make
>make install
>export LD_LIBRARY_PATH=/opt/gcc72/lib64:$LD_LIBRARY_PATH ; /path/to/thunder-trader thunder-trader.conf.default 1
Run.SystemNumber=1 [20181021T062516.546639]
```
Then you can use the Monitor to connect the thunder-trader.
## Screenshots
<p><b>Software running screenshots:</b><br>
The Monitor(Coming soon):<br>
<img src='https://github.com/solopointer/thunder-trader/blob/master/assets/hft-monitor1.png' width=600><br><br>
<img src='https://github.com/solopointer/thunder-trader/blob/master/assets/hft-monitor2.png' width=600><br><br>
<img src='https://github.com/solopointer/thunder-trader/blob/master/assets/hft-monitor3.png' width=600><br><br>
<img src='https://github.com/solopointer/thunder-trader/blob/master/assets/hft-monitor4.png' width=600><br><br>
The strategy research platform(Coming soon):<br>
<img src='https://github.com/solopointer/thunder-trader/blob/master/assets/hft-research1.png' width=600><br><br>
</p>

Particular attention:
If you encounter an 
```
^C*** Error in `./thunder-trader': double free or corruption (!prev): 0x0000000001e32bb0 ***
```
like error when run thunder-trader, don't worry. This is a bug in CTPLibrary that usually appears when the process exit, 
but does not affect the normal operation of the program.Turn off the ctp option, or tell me how to avoid this error if you knows please.


If you like this project, give me a star ^_^<img src='https://github.com/solopointer/thunder-trader/blob/master/assets/star.jpeg' width=30>


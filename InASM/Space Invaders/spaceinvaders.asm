include emu8086.inc  
  
  
ORG    100h
mov ax, 0b800h
mov ds, ax

;carreau 1
    mov [208], 0B1h
    mov [209], 0010b
    mov [210], 0B1h
    mov [211], 0010b
    mov [212], 0B1h
    mov [213], 0010b
    mov [368], 0B1h
    mov [369], 0010b
    mov [370], 0B1h
    mov [371], 0010b
    mov [372], 0B1h
    mov [373], 0010b
    mov [528], 0B1h
    mov [529], 0010b
    mov [530], 0B1h
    mov [531], 0010b
    mov [532], 0B1h
    mov [533], 0010b 
    ;carreau 2
    mov [244], 0B1h
    mov [245], 0010b
    mov [246], 0B1h
    mov [247], 0010b
    mov [248], 0B1h
    mov [249], 0010b
    mov [404], 0B1h
    mov [405], 0010b
    mov [406], 0B1h
    mov [407], 0010b
    mov [408], 0B1h
    mov [409], 0010b
    mov [564], 0B1h
    mov [565], 0010b
    mov [566], 0B1h
    mov [567], 0010b
    mov [568], 0B1h
    mov [569], 0010b
    ;carreau 4
    mov [694], 0B1h
    mov [695], 0010b
    mov [696], 0B1h
    mov [697], 0010b
    mov [698], 0B1h
    mov [699], 0010b
    mov [854], 0B1h
    mov [855], 0010b
    mov [856], 0B1h
    mov [857], 0010b
    mov [858], 0B1h
    mov [859], 0010b
    mov [1014], 0B1h
    mov [1015], 0010b
    mov [1016], 0B1h
    mov [1017], 0010b
    mov [1018], 0B1h
    mov [1019], 0010b
    ;carreau 3
    mov [722], 0B1h
    mov [723], 0010b
    mov [720], 0B1h
    mov [721], 0010b
    mov [718], 0B1h
    mov [719], 0010b
    mov [882], 0B1h
    mov [883], 0010b
    mov [880], 0B1h
    mov [881], 0010b
    mov [878], 0B1h 
    mov [879], 0010b
    mov [1042], 0B1h
    mov [1043], 0010b
    mov [1040], 0B1h
    mov [1041], 0010b
    mov [1038], 0B1h
    mov [1039], 0010b
    ;carreau 5
    mov [1168], 0B1h
    mov [1169], 0010b
    mov [1170], 0B1h
    mov [1171], 0010b
    mov [1172], 0B1h
    mov [1173], 0010b
    mov [1328], 0B1h
    mov [1329], 0010b
    mov [1330], 0B1h
    mov [1331], 0010b
    mov [1332], 0B1h
    mov [1333], 0010b
    mov [1488], 0B1h
    mov [1489], 0010b
    mov [1490], 0B1h
    mov [1491], 0010b
    mov [1492], 0B1h
    mov [1493], 0010b
    ;carreau 6
    mov [1174], 0B1h
    mov [1175], 0010b
    mov [1176], 0B1h
    mov [1177], 0010b
    mov [1178], 0B1h
    mov [1179], 0010b
    mov [1334], 0B1h
    mov [1335], 0010b
    mov [1336], 0B1h
    mov [1337], 0010b
    mov [1338], 0B1h
    mov [1339], 0010b
    mov [1494], 0B1h
    mov [1495], 0010b
    mov [1496], 0B1h
    mov [1497], 0010b
    mov [1498], 0B1h
    mov [1499], 0010b
    ;carreau 7
    mov [1180], 0B1h
    mov [1181], 0010b
    mov [1182], 0B1h
    mov [1183], 0010b
    mov [1184], 0B1h
    mov [1185], 0010b
    mov [1340], 0B1h
    mov [1341], 0010b
    mov [1342], 0B1h
    mov [1343], 0010b
    mov [1344], 0B1h
    mov [1345], 0010b
    mov [1500], 0B1h
    mov [1501], 0010b
    mov [1502], 0B1h
    mov [1503], 0010b
    mov [1504], 0B1h
    mov [1505], 0010b
    ;carreau 8 
    mov [1186], 0B1h
    mov [1187], 0010b
    mov [1188], 0B1h
    mov [1189], 0010b
    mov [1190], 0B1h
    mov [1191], 0010b
    mov [1346], 0B1h
    mov [1347], 0010b
    mov [1348], 0B1h
    mov [1349], 0010b
    mov [1350], 0B1h
    mov [1351], 0010b
    mov [1506], 0B1h
    mov [1507], 0010b
    mov [1508], 0B1h
    mov [1509], 0010b
    mov [1510], 0B1h
    mov [1511], 0010b
    ;carreau 9
    mov [1192], 0B1h
    mov [1193], 0010b
    mov [1194], 0B1h
    mov [1195], 0010b
    mov [1196], 0B1h
    mov [1197], 0010b
    mov [1352], 0B1h
    mov [1353], 0010b
    mov [1354], 0B1h
    mov [1355], 0010b
    mov [1356], 0B1h
    mov [1357], 0010b
    mov [1512], 0B1h
    mov [1513], 0010b
    mov [1514], 0B1h
    mov [1515], 0010b
    mov [1516], 0B1h
    mov [1517], 0010b
    ;carreau 10
    mov [1198], 0B1h
    mov [1199], 0010b
    mov [1200], 0B1h
    mov [1201], 0010b
    mov [1202], 0B1h
    mov [1203], 0010b
    mov [1358], 0B1h
    mov [1359], 0010b
    mov [1360], 0B1h
    mov [1361], 0010b
    mov [1362], 0B1h
    mov [1363], 0010b
    mov [1518], 0B1h
    mov [1519], 0010b
    mov [1520], 0B1h
    mov [1521], 0010b
    mov [1522], 0B1h
    mov [1523], 0010b
    ;carreau 11
    mov [1204], 0B1h
    mov [1205], 0010b
    mov [1206], 0B1h
    mov [1207], 0010b
    mov [1208], 0B1h
    mov [1209], 0010b
    mov [1364], 0B1h
    mov [1365], 0010b
    mov [1366], 0B1h
    mov [1367], 0010b
    mov [1368], 0B1h
    mov [1369], 0010b
    mov [1524], 0B1h
    mov [1525], 0010b
    mov [1526], 0B1h
    mov [1527], 0010b
    mov [1528], 0B1h
    mov [1529], 0010b
    ;carreau 12
    mov [1642], 0B1h
    mov [1643], 0010b
    mov [1644], 0B1h
    mov [1645], 0010b
    mov [1646], 0B1h
    mov [1647], 0010b
    mov [1802], 0B1h
    mov [1803], 0010b
    mov [1804], 0B1h
    mov [1805], 0010b
    mov [1806], 0B1h
    mov [1807], 0010b
    mov [1962], 0B1h
    mov [1963], 0010b
    mov [1964], 0B1h
    mov [1965], 0010b
    mov [1966], 0B1h
    mov [1967], 0010b
    ;carreau 13
    mov [1648], 0B1h
    mov [1649], 0010b
    mov [1650], 0B1h
    mov [1651], 0010b
    mov [1652], 0B1h
    mov [1653], 0010b
    mov [1808], 0B1h
    mov [1809], 0010b
    mov [1810], 0B1h
    mov [1811], 0010b
    mov [1812], 0B1h
    mov [1813], 0010b
    mov [1968], 0B1h
    mov [1969], 0010b
    mov [1970], 0B1h
    mov [1971], 0010b
    mov [1972], 0B1h
    mov [1973], 0010b
    ;carreau 14
    mov [1660], 0B1h
    mov [1661], 0010b
    mov [1662], 0B1h
    mov [1663], 0010b
    mov [1664], 0B1h
    mov [1665], 0010b
    mov [1820], 0B1h
    mov [1821], 0010b
    mov [1822], 0B1h
    mov [1823], 0010b
    mov [1824], 0B1h
    mov [1825], 0010b
    mov [1980], 0B1h
    mov [1981], 0010b
    mov [1982], 0B1h
    mov [1983], 0010b
    mov [1984], 0B1h
    mov [1985], 0010b
    ;carreau 15
    mov [1666], 0B1h
    mov [1667], 0010b
    mov [1668], 0B1h
    mov [1669], 0010b
    mov [1670], 0B1h
    mov [1671], 0010b
    mov [1826], 0B1h
    mov [1827], 0010b
    mov [1828], 0B1h
    mov [1829], 0010b
    mov [1830], 0B1h
    mov [1831], 0010b
    mov [1986], 0B1h
    mov [1987], 0010b
    mov [1988], 0B1h
    mov [1989], 0010b
    mov [1990], 0B1h
    mov [1991], 0010b
    ;carreau 16
    mov [1672], 0B1h
    mov [1673], 0010b
    mov [1674], 0B1h
    mov [1675], 0010b
    mov [1676], 0B1h
    mov [1677], 0010b
    mov [1832], 0B1h
    mov [1833], 0010b
    mov [1834], 0B1h
    mov [1835], 0010b
    mov [1836], 0B1h
    mov [1837], 0010b
    mov [1992], 0B1h
    mov [1993], 0010b
    mov [1994], 0B1h
    mov [1995], 0010b
    mov [1996], 0B1h
    mov [1997], 0010b
    ;carreau 17
    mov [1684], 0B1h
    mov [1685], 0010b
    mov [1686], 0B1h
    mov [1687], 0010b
    mov [1688], 0B1h
    mov [1689], 0010b
    mov [1844], 0B1h
    mov [1845], 0010b
    mov [1846], 0B1h
    mov [1847], 0010b
    mov [1848], 0B1h
    mov [1849], 0010b
    mov [2004], 0B1h
    mov [2005], 0010b
    mov [2006], 0B1h
    mov [2007], 0010b
    mov [2008], 0B1h
    mov [2009], 0010b
    ;carreau 18
    mov [1690], 0B1h
    mov [1691], 0010b
    mov [1692], 0B1h
    mov [1693], 0010b
    mov [1694], 0B1h
    mov [1695], 0010b
    mov [1850], 0B1h
    mov [1851], 0010b
    mov [1852], 0B1h
    mov [1853], 0010b
    mov [1854], 0B1h
    mov [1855], 0010b
    mov [2010], 0B1h
    mov [2011], 0010b
    mov [2012], 0B1h
    mov [2013], 0010b
    mov [2014], 0B1h
    mov [2015], 0010b
    ;carreau 19
    mov [2116], 0B1h
    mov [2117], 0010b
    mov [2118], 0B1h
    mov [2119], 0010b
    mov [2120], 0B1h
    mov [2121], 0010b
    mov [2276], 0B1h
    mov [2277], 0010b
    mov [2278], 0B1h
    mov [2279], 0010b
    mov [2280], 0B1h
    mov [2281], 0010b
    mov [2436], 0B1h
    mov [2437], 0010b
    mov [2438], 0B1h
    mov [2439], 0010b
    mov [2440], 0B1h
    mov [2441], 0010b
    ;carreau 20
    mov [2122], 0B1h
    mov [2123], 0010b
    mov [2124], 0B1h
    mov [2125], 0010b
    mov [2126], 0B1h
    mov [2127], 0010b
    mov [2282], 0B1h
    mov [2283], 0010b
    mov [2284], 0B1h
    mov [2285], 0010b
    mov [2286], 0B1h
    mov [2287], 0010b
    mov [2442], 0B1h
    mov [2443], 0010b
    mov [2444], 0B1h
    mov [2445], 0010b
    mov [2446], 0B1h
    mov [2447], 0010b
    ;carreau 21
    mov [2128], 0B1h
    mov [2129], 0010b
    mov [2130], 0B1h
    mov [2131], 0010b
    mov [2132], 0B1h
    mov [2133], 0010b
    mov [2288], 0B1h
    mov [2289], 0010b
    mov [2290], 0B1h
    mov [2291], 0010b
    mov [2292], 0B1h
    mov [2293], 0010b
    mov [2448], 0B1h
    mov [2449], 0010b
    mov [2450], 0B1h
    mov [2451], 0010b
    mov [2452], 0B1h
    mov [2453], 0010b
    ;carreau 22 
    mov [2134], 0B1h
    mov [2135], 0010b
    mov [2136], 0B1h
    mov [2137], 0010b
    mov [2138], 0B1h
    mov [2139], 0010b
    mov [2294], 0B1h
    mov [2295], 0010b
    mov [2296], 0B1h
    mov [2297], 0010b
    mov [2298], 0B1h
    mov [2299], 0010b
    mov [2454], 0B1h
    mov [2455], 0010b
    mov [2456], 0B1h
    mov [2457], 0010b
    mov [2458], 0B1h
    mov [2459], 0010b
    ;carreau 23
    mov [2140], 0B1h
    mov [2141], 0010b
    mov [2142], 0B1h
    mov [2143], 0010b
    mov [2144], 0B1h
    mov [2145], 0010b
    mov [2300], 0B1h
    mov [2301], 0010b
    mov [2302], 0B1h
    mov [2303], 0010b
    mov [2304], 0B1h
    mov [2305], 0010b
    mov [2460], 0B1h
    mov [2461], 0010b
    mov [2462], 0B1h
    mov [2463], 0010b
    mov [2464], 0B1h
    mov [2465], 0010b
    ;carreau 24
    mov [2146], 0B1h
    mov [2147], 0010b
    mov [2148], 0B1h
    mov [2149], 0010b
    mov [2150], 0B1h
    mov [2151], 0010b
    mov [2306], 0B1h
    mov [2307], 0010b
    mov [2308], 0B1h
    mov [2309], 0010b
    mov [2310], 0B1h
    mov [2311], 0010b
    mov [2466], 0B1h
    mov [2467], 0010b
    mov [2468], 0B1h
    mov [2469], 0010b
    mov [2470], 0B1h
    mov [2471], 0010b
    ;carreau 25
    mov [2152], 0B1h
    mov [2153], 0010b
    mov [2154], 0B1h
    mov [2155], 0010b
    mov [2156], 0B1h
    mov [2157], 0010b
    mov [2312], 0B1h
    mov [2313], 0010b
    mov [2314], 0B1h
    mov [2315], 0010b
    mov [2316], 0B1h
    mov [2317], 0010b
    mov [2472], 0B1h
    mov [2473], 0010b
    mov [2474], 0B1h
    mov [2475], 0010b
    mov [2476], 0B1h
    mov [2477], 0010b
    ;carreau 26
    mov [2158], 0B1h
    mov [2159], 0010b
    mov [2160], 0B1h
    mov [2161], 0010b
    mov [2162], 0B1h
    mov [2163], 0010b
    mov [2318], 0B1h
    mov [2319], 0010b
    mov [2320], 0B1h
    mov [2321], 0010b
    mov [2322], 0B1h
    mov [2323], 0010b
    mov [2478], 0B1h
    mov [2479], 0010b
    mov [2480], 0B1h
    mov [2481], 0010b
    mov [2482], 0B1h
    mov [2483], 0010b
    ;carreau 27
    mov [2164], 0B1h
    mov [2165], 0010b
    mov [2166], 0B1h
    mov [2167], 0010b
    mov [2168], 0B1h
    mov [2169], 0010b
    mov [2324], 0B1h
    mov [2325], 0010b
    mov [2326], 0B1h
    mov [2327], 0010b
    mov [2328], 0B1h
    mov [2329], 0010b
    mov [2484], 0B1h
    mov [2485], 0010b
    mov [2486], 0B1h
    mov [2487], 0010b
    mov [2488], 0B1h
    mov [2489], 0010b
    ;carreau 28
    mov [2170], 0B1h
    mov [2171], 0010b
    mov [2172], 0B1h
    mov [2173], 0010b
    mov [2174], 0B1h
    mov [2175], 0010b
    mov [2330], 0B1h
    mov [2331], 0010b
    mov [2332], 0B1h
    mov [2333], 0010b
    mov [2334], 0B1h
    mov [2335], 0010b
    mov [2490], 0B1h
    mov [2491], 0010b
    mov [2492], 0B1h
    mov [2493], 0010b
    mov [2494], 0B1h
    mov [2495], 0010b
    ;carreau 29
    mov [2176], 0B1h
    mov [2177], 0010b
    mov [2178], 0B1h
    mov [2179], 0010b
    mov [2180], 0B1h
    mov [2181], 0010b
    mov [2336], 0B1h
    mov [2337], 0010b
    mov [2338], 0B1h
    mov [2339], 0010b
    mov [2340], 0B1h
    mov [2341], 0010b
    mov [2496], 0B1h
    mov [2497], 0010b
    mov [2498], 0B1h
    mov [2499], 0010b
    mov [2500], 0B1h
    mov [2501], 0010b
    ;carreau 30
    mov [2596], 0B1h
    mov [2597], 0010b
    mov [2598], 0B1h
    mov [2599], 0010b
    mov [2600], 0B1h
    mov [2601], 0010b
    mov [2756], 0B1h
    mov [2757], 0010b
    mov [2758], 0B1h
    mov [2759], 0010b
    mov [2760], 0B1h
    mov [2761], 0010b
    mov [2916], 0B1h
    mov [2917], 0010b
    mov [2918], 0B1h
    mov [2919], 0010b
    mov [2920], 0B1h
    mov [2921], 0010b
    ;carreau 31
    mov [2608], 0B1h
    mov [2609], 0010b
    mov [2610], 0B1h
    mov [2611], 0010b
    mov [2612], 0B1h
    mov [2613], 0010b
    mov [2768], 0B1h
    mov [2769], 0010b
    mov [2770], 0B1h
    mov [2771], 0010b
    mov [2772], 0B1h
    mov [2773], 0010b
    mov [2928], 0B1h
    mov [2929], 0010b
    mov [2930], 0B1h
    mov [2931], 0010b
    mov [2932], 0B1h
    mov [2933], 0010b
    ;carreau 32
    mov [2614], 0B1h
    mov [2615], 0010b
    mov [2616], 0B1h
    mov [2617], 0010b
    mov [2618], 0B1h
    mov [2619], 0010b
    mov [2774], 0B1h
    mov [2775], 0010b
    mov [2776], 0B1h
    mov [2777], 0010b
    mov [2778], 0B1h
    mov [2779], 0010b
    mov [2934], 0B1h
    mov [2935], 0010b
    mov [2936], 0B1h
    mov [2937], 0010b
    mov [2938], 0B1h
    mov [2939], 0010b
    ;carreau 33
    mov [2620], 0B1h
    mov [2621], 0010b
    mov [2622], 0B1h
    mov [2623], 0010b
    mov [2624], 0B1h
    mov [2625], 0010b
    mov [2780], 0B1h
    mov [2781], 0010b
    mov [2782], 0B1h
    mov [2783], 0010b
    mov [2784], 0B1h
    mov [2785], 0010b
    mov [2940], 0B1h
    mov [2941], 0010b
    mov [2942], 0B1h
    mov [2943], 0010b
    mov [2944], 0B1h
    mov [2945], 0010b
    ;carreau 34
    mov [2626], 0B1h
    mov [2627], 0010b
    mov [2628], 0B1h
    mov [2629], 0010b
    mov [2630], 0B1h
    mov [2631], 0010b
    mov [2786], 0B1h
    mov [2787], 0010b
    mov [2788], 0B1h
    mov [2789], 0010b
    mov [2790], 0B1h
    mov [2791], 0010b
    mov [2946], 0B1h
    mov [2947], 0010b
    mov [2948], 0B1h
    mov [2949], 0010b
    mov [2950], 0B1h
    mov [2951], 0010b
    ;carreau 35
    mov [2632], 0B1h
    mov [2633], 0010b
    mov [2634], 0B1h
    mov [2635], 0010b
    mov [2636], 0B1h
    mov [2637], 0010b
    mov [2792], 0B1h
    mov [2793], 0010b
    mov [2794], 0B1h
    mov [2795], 0010b
    mov [2796], 0B1h
    mov [2797], 0010b
    mov [2952], 0B1h
    mov [2953], 0010b
    mov [2954], 0B1h
    mov [2955], 0010b
    mov [2956], 0B1h
    mov [2957], 0010b
    ;carreau 36
    mov [2638], 0B1h
    mov [2639], 0010b
    mov [2640], 0B1h
    mov [2641], 0010b
    mov [2642], 0B1h
    mov [2643], 0010b
    mov [2798], 0B1h
    mov [2799], 0010b
    mov [2800], 0B1h
    mov [2801], 0010b
    mov [2802], 0B1h
    mov [2803], 0010b
    mov [2958], 0B1h
    mov [2959], 0010b
    mov [2960], 0B1h
    mov [2961], 0010b
    mov [2962], 0B1h
    mov [2963], 0010b
    ;carreau 37
    mov [2644], 0B1h
    mov [2645], 0010b
    mov [2646], 0B1h
    mov [2647], 0010b
    mov [2648], 0B1h
    mov [2649], 0010b
    mov [2804], 0B1h
    mov [2805], 0010b
    mov [2806], 0B1h
    mov [2807], 0010b
    mov [2808], 0B1h
    mov [2809], 0010b
    mov [2964], 0B1h
    mov [2965], 0010b
    mov [2966], 0B1h
    mov [2967], 0010b
    mov [2968], 0B1h
    mov [2969], 0010b 
    ;carreau 38
    mov [2656], 0B1h
    mov [2657], 0010b
    mov [2658], 0B1h
    mov [2659], 0010b
    mov [2660], 0B1h
    mov [2661], 0010b
    mov [2816], 0B1h
    mov [2817], 0010b
    mov [2818], 0B1h
    mov [2819], 0010b
    mov [2820], 0B1h
    mov [2821], 0010b
    mov [2976], 0B1h
    mov [2977], 0010b
    mov [2978], 0B1h
    mov [2979], 0010b
    mov [2980], 0B1h
    mov [2981], 0010b
    ;carreau 39
    mov [3076], 0B1h
    mov [3077], 0010b
    mov [3078], 0B1h
    mov [3079], 0010b
    mov [3080], 0B1h
    mov [3081], 0010b
    mov [3236], 0B1h
    mov [3237], 0010b
    mov [3238], 0B1h
    mov [3239], 0010b
    mov [3240], 0B1h
    mov [3241], 0010b
    mov [3396], 0B1h
    mov [3397], 0010b
    mov [3398], 0B1h
    mov [3399], 0010b
    mov [3400], 0B1h
    mov [3401], 0010b
    ;carreau 40
    mov [3088], 0B1h
    mov [3089], 0010b
    mov [3090], 0B1h
    mov [3091], 0010b
    mov [3092], 0B1h
    mov [3093], 0010b
    mov [3248], 0B1h
    mov [3249], 0010b
    mov [3250], 0B1h
    mov [3251], 0010b
    mov [3252], 0B1h
    mov [3253], 0010b
    mov [3408], 0B1h
    mov [3409], 0010b
    mov [3410], 0B1h
    mov [3411], 0010b
    mov [3412], 0B1h
    mov [3413], 0010b
    ;carreau 41
    mov [3124], 0B1h
    mov [3125], 0010b
    mov [3126], 0B1h
    mov [3127], 0010b
    mov [3128], 0B1h
    mov [3129], 0010b
    mov [3284], 0B1h
    mov [3285], 0010b
    mov [3286], 0B1h
    mov [3287], 0010b
    mov [3288], 0B1h
    mov [3289], 0010b
    mov [3444], 0B1h
    mov [3445], 0010b
    mov [3446], 0B1h
    mov [3447], 0010b
    mov [3448], 0B1h
    mov [3449], 0010b
    ;carreau 42
    mov [3136], 0B1h
    mov [3137], 0010b
    mov [3138], 0B1h
    mov [3139], 0010b
    mov [3140], 0B1h
    mov [3141], 0010b
    mov [3296], 0B1h
    mov [3297], 0010b
    mov [3298], 0B1h
    mov [3299], 0010b
    mov [3300], 0B1h
    mov [3301], 0010b
    mov [3456], 0B1h
    mov [3457], 0010b
    mov [3458], 0B1h
    mov [3459], 0010b
    mov [3460], 0B1h
    mov [3461], 0010b
    ;carreau 43
    mov [3574], 0B1h
    mov [3575], 0010b
    mov [3576], 0B1h
    mov [3577], 0010b
    mov [3578], 0B1h
    mov [3579], 0010b
    mov [3734], 0B1h
    mov [3735], 0010b
    mov [3736], 0B1h
    mov [3737], 0010b
    mov [3738], 0B1h
    mov [3739], 0010b

    ;carreau 44
    mov [3580], 0B1h
    mov [3581], 0010b
    mov [3582], 0B1h
    mov [3583], 0010b
    mov [3584], 0B1h
    mov [3585], 0010b
    mov [3740], 0B1h
    mov [3741], 0010b
    mov [3742], 0B1h
    mov [3743], 0010b
    mov [3744], 0B1h
    mov [3745], 0010b

    ;carreau 45
    mov [3592], 0B1h
    mov [3593], 0010b
    mov [3594], 0B1h
    mov [3595], 0010b
    mov [3596], 0B1h
    mov [3597], 0010b
    mov [3752], 0B1h
    mov [3753], 0010b
    mov [3754], 0B1h
    mov [3755], 0010b
    mov [3756], 0B1h
    mov [3757], 0010b

    ;carreau 46
    mov [3598], 0B1h
    mov [3599], 0010b
    mov [3600], 0B1h
    mov [3601], 0010b
    mov [3602], 0B1h
    mov [3603], 0010b
    mov [3758], 0B1h
    mov [3759], 0010b
    mov [3760], 0B1h
    mov [3761], 0010b
    mov [3762], 0B1h
    mov [3763], 0010b
    
mov [274], "S"
mov [275], 01001011b
mov [436], "p"
mov [437], 01001011b
mov [598], "a"
mov [599], 01001011b
mov [760], "c"
mov [761], 01001011b
mov [922], "e"
mov [923], 01001011b
mov [588], "I"
mov [589], 01001011b
mov [750], "n"
mov [751], 01001011b
mov [912], "v"
mov [913], 01001011b
mov [1074], "a"
mov [1075], 01001011b
mov [1236], "d"
mov [1237], 01001011b
mov [1398], "e"
mov [1399], 01001011b
mov [1560], "r"
mov [1561], 01001011b
mov [1722], "s"
mov [1723], 01001011b


    
    play:
    
    mov cx, 3
    push_p:
    mov bx, 2350
    mov [bx], 'P'
    mov [bx+1], 1010b 
    mov [bx+2], 'o'
    mov [bx+3], 1010b
    mov [bx+4], 'u'
    mov [bx+5], 1010b
    mov [bx+6], 'r'
    mov [bx+7], 1010b
    mov [bx+10], 'J'
    mov [bx+11], 1010b
    mov [bx+12], 'o' 
    mov [bx+13], 1010b
    mov [bx+14], 'u' 
    mov [bx+15], 1010b
    mov [bx+16], 'e' 
    mov [bx+17], 1010b
    mov [bx+18], 'r' 
    mov [bx+19], 1010b
    mov [bx+22], 'A' 
    mov [bx+23], 1010b
    mov [bx+24], 'p' 
    mov [bx+25], 1010b
    mov [bx+26], 'p' 
    mov [bx+27], 1010b
    mov [bx+28], 'u' 
    mov [bx+29], 1010b
    mov [bx+30], 'y' 
    mov [bx+31], 1010b
    mov [bx+32], 'e' 
    mov [bx+33], 1010b
    mov [bx+34], 'z' 
    mov [bx+35], 1010b
    mov [bx+38], 's' 
    mov [bx+39], 1010b
    mov [bx+40], 'u' 
    mov [bx+41], 1010b
    mov [bx+42], 'r' 
    mov [bx+43], 1010b
    mov [bx+46], 'P' 
    mov [bx+47], 1010b
    loop push_p
    
    mov cx, 3
    push_p1:
    mov [bx], 0
    mov [bx+2], 0
    mov [bx+4], 0
    mov [bx+6], 0
    mov [bx+10], 0
    mov [bx+12], 0
    mov [bx+14], 0
    mov [bx+16], 0
    mov [bx+18], 0
    mov [bx+22], 0
    mov [bx+24], 0
    mov [bx+26], 0
    mov [bx+28], 0
    mov [bx+30], 0
    mov [bx+32], 0
    mov [bx+34], 0
    mov [bx+38], 0
    mov [bx+40], 0
    mov [bx+42], 0
    mov [bx+44], 0
    loop push_p1
    
    
    
    mov ah, 1
    int 16h
    cmp ah, 0x19h
    je affichage_niveau1
    loop play  
    
;clear l'ecran    
affichage_niveau1:
pusha
XOR AX, AX 
XOR BX, BX 
XOR CX, CX
XOR DX, DX
mov ah, 6
mov dx, 174fh
int 10h
popa 

;vide le buffer pour que l'appuie sur une touche ne face pas beug le prog
mov ah, 0ch
int 21h

mov bx, 0
mov cx, 79  

bordureh1:
mov [bx], 0B1h 
mov [bx+1], 00001110b
add bx, 2 
loop bordureh1

GOTOXY 1, 0
print 'Score: '

mov bx, 0
mov cx, 25
bordureg1:
mov [bx], 0B1h 
mov [bx+1], 00001110b 
add bx, 160
loop bordureg1
XOR BX, BX

mov bx, 158
mov cx, 25
bordured1:
mov [bx], 0B1h 
mov [bx+1], 00001110b 
add bx, 160
loop bordured1

mov bx, 2102
mov cx, 1

ennemis1:
push cx
mov cx, 10
 
ligne_ennemis1:
mov [bx], '('
mov [bx+1], 1100b
mov [bx+2], '-'
mov [bx+3], 1100b
mov [bx+4], 'O'
mov [bx+5], 1100b
mov [bx+6], '-'      
mov [bx+7], 1100b
mov [bx+8], ')'      
mov [bx+9], 1100b
add bx, 12
loop ligne_ennemis1 
pop cx
loop ennemis1

mov bx, 3388
push bx
mov cx, 4

abri0_1:
mov [bx-1], 11101110b
mov [bx-2], 'D'
mov [bx+1], 11101110b
mov [bx], 'D'
mov [bx+9], 11101110b
mov [bx+8], 'D' 
mov [bx+11], 11101110b
mov [bx+10], 'D'
add bx, 32
loop abri0_1

pop bx
sub bx, 160
push bx
mov cx, 4

abri1_1:
mov [bx-1], 11101110b
mov [bx-2], 'D'
mov [bx+1], 11101110b
mov [bx], 'D'
mov [bx+3], 11101110b
mov [bx+2], 'D'
mov [bx+7], 11101110b
mov [bx+6], 'D'
mov [bx+9], 11101110b
mov [bx+8], 'D' 
mov [bx+11], 11101110b
mov [bx+10], 'D'
add bx, 32
loop abri1_1 
    
pop bx
sub bx, 160
push bx
mov cx, 4

abri2_1:
mov [bx-1], 11101110b
mov [bx-2], 'D'
mov [bx+1], 11101110b
mov [bx], 'D'
mov [bx+3], 11101110b
mov [bx+2], 'D'
mov [bx+5], 11101110b
mov [bx+4], 'D'
mov [bx+7], 11101110b
mov [bx+6], 'D'
mov [bx+9], 11101110b
mov [bx+8], 'D'
mov [bx+10], 'D'
mov [bx+11], 11101110b
add bx, 32
loop abri2_1 

mov bx, 3842 
mov cx, 78

bordurebas1:
mov [bx], 2Eh
mov [bx+1], 0000b
add bx, 2
loop bordurebas1

XOR BX, BX

;initialisation vaisseau
mov di, 3918
mov bx, 3918
mov cx, 0
mov [bx-2], '>'
mov [bx-1], 1011b
mov [bx], 0E2h
mov [bx+1], 1011b
mov [bx+2], '<'
mov [bx+3], 1011b

mov cx, 10
mov ax, 0

main1:
push bx
call allie1
pop bx 
call ennemi1
call test_nbennemi1
loop main1   

;----->Commencement PROCEDURE<-----

allie1 PROC
    push ax
    call deplacement_allie1
    call tire_allie1 
    pop ax
    RET
allie1 ENDP

ennemi1 PROC 
    call deplacement_ennemi1
    push bx 
    call tire_ennemi1 
    pop bx  
    RET
ennemi1 ENDP

test_nbennemi1 PROC
    cmp cx, 0
    je affichage_niveau2
    add cx, 1
    RET
test_nbennemi1 ENDP

score1 PROC 
    GOTOXY 7, 0  
    mov ax, cx
    sub ax, 10 
    neg ax
    CALL print_num      ; print number in AX.
    RET                   ; return to operating system 
score1 ENDP

deplacement_allie1 PROC
    mov ah, 1
    int 16h
    cmp ah, 0x4bh
    je deplacementg1
    cmp ah, 0x4dh
    je deplacementd1
    RET
deplacement_allie1 ENDP

deplacement_ennemi1 PROC
    cmp bx, 2080
    jl value_ennemi1
    cmp bx, 2240
    ja value_ennemi1
    cmp dl, 0
    je deplacement_droite0_1   
    cmp dl, 1
    je deplacement_gauche0_1
    RET
deplacement_ennemi1 ENDP

tire_allie1 PROC
    mov ah, 1
    int 16h
    cmp ah, 0x48h
    je tire_test1
    cmp dh, 1
    je tire_deplacement1
    RET
tire_allie1 ENDP

tire_ennemi1 PROC
    call test_bx
    cmp al, 0
    jne deplacement_tire_ennemi1 
    RET
tire_ennemi1 ENDP  

test_bx1 PROC
    cmp [bx], 'O'
    je test_lancement_tire_ennemi1
    RET  
test_bx1 ENDP

;----->Fin PROCEDURE<-----

deplacementg1:
    mov bx, di
    cmp [bx-4], 2Eh
    jne deplacementd1
    mov [bx+2], 2Eh
    mov [bx+3], 0000b
    mov [bx], '<'
    mov [bx+1], 1011b
    sub bx, 2
    mov [bx], 0E2h
    mov [bx+1], 1011b
    mov [bx-2], '>'
    mov [bx-1], 1011b
    mov di, bx
    mov ah, 0ch
    int 21h
    RET
    

            
deplacementd1:
    mov bx, di
    cmp [bx+4], 2Eh
    jne deplacementg1 
    mov [bx-2], 2Eh
    mov [bx-1], 0000b
    mov [bx], '>'
    mov [bx+1], 1011b
    add bx, 2
    mov [bx], 0E2h
    mov [bx+1], 1011b
    mov [bx+2], '<'
    mov [bx+3], 1011b
    mov di, bx
    mov ah, 0ch
    int 21h
    RET

test_lancement_tire_ennemi1:
    cmp al, 0  
    je lancement_tire_ennemi1 
    sub al, 1  
    RET
    
lancement_tire_ennemi1:
    mov al, 9
    mov [bx+160], 0FEh
    mov [bx+161], 0100b
    add bx, 160 
    mov bp, bx
    RET   
    
deplacement_tire_ennemi1:
    mov bx, bp 
    cmp [bx+160], 0FEh
    je efface_missile0_1
    add bx, 160
    mov [bx-160], 0
    mov [bx], 0FEh
    mov [bx+1], 0100b
    cmp [bx+160], 'D'
    je efface_abri_ennemi1
    cmp [bx+160], 2Eh
    je efface_bordure_ennemi1  
    cmp [bx+160], '<'
    je fin_partie  
    cmp [bx+160], '>'
    je fin_partie 
    cmp [bx+160], 0E2h
    je fin_partie 
    mov bp, bx
    RET
    
tire1:
    mov dh, 1
    mov si, di
    sub si, 160
    mov bx, si
    mov [bx], 0FEh
    mov [bx+1], 1111b
    mov si, bx
    mov ah, 0ch
    int 21h
    RET
    
tire_deplacement1:
    mov bx, si
    sub bx, 160
    mov [bx], 0FEh
    mov [bx+1], 1111b 
    mov [bx+160], 0     
    cmp [bx-160], 'D'
    je casse_abri1
    cmp [bx-160], 'O'
    je efface_ennemi_entier1
    cmp [bx-162], '('
    je efface_ennemi_tiret_gauche1
    cmp [bx-158], ')'
    je efface_ennemi_tiret_droite1
    cmp [bx-162], '-'
    je efface_ennemi_droite1
    cmp [bx-158], '-'
    je efface_ennemi_gauche1
    cmp [bx-160], 0B1h
    je efface_bordure1
    cmp [bx-160], 0FEh
    je efface_missile1_1 
    mov si, bx
    RET 

efface_ennemi_tiret_droite1:
    mov [bx-168], 0
    mov [bx-167], 0
    mov [bx-166], 0
    mov [bx-165], 0 
    mov [bx-164], 0
    mov [bx-163], 0
    mov [bx-162], 0
    mov [bx-161], 0
    mov [bx-160], 0
    mov [bx-159], 0
    mov [bx-158], 0
    mov [bx-157], 0
    mov [bx], 0
    mov dh, 0
    sub cx, 1 
    pusha
    call score1
    popa
    mov ah, 0ch
    int 21h
    RET
    
efface_ennemi_tiret_gauche1:
    mov [bx-160], 0
    mov [bx-159], 0
    mov [bx-162], 0
    mov [bx-161], 0
    mov [bx-158], 0
    mov [bx-157], 0
    mov [bx-156], 0
    mov [bx-155], 0
    mov [bx-154], 0
    mov [bx-153], 0
    mov [bx], 0
    mov dh, 0
    sub cx, 1 
    pusha
    call score1
    popa
    mov ah, 0ch
    int 21h
    RET
    

efface_ennemi_droite1:
    mov [bx-168], 0
    mov [bx-167], 0
    mov [bx-166], 0
    mov [bx-165], 0 
    mov [bx-164], 0
    mov [bx-163], 0
    mov [bx-162], 0
    mov [bx-161], 0
    mov [bx-160], 0
    mov [bx-159], 0
    mov [bx], 0
    mov dh, 0
    sub cx, 1
    pusha
    call score1
    popa
    mov ah, 0ch
    int 21h
    RET

efface_ennemi_gauche1:
    mov [bx-160], 0
    mov [bx-159], 0
    mov [bx-158], 0
    mov [bx-157], 0
    mov [bx-156], 0
    mov [bx-155], 0
    mov [bx-154], 0
    mov [bx-153], 0
    mov [bx-152], 0
    mov [bx-151], 0
    mov [bx], 0
    mov dh, 0 
    sub cx, 1
    pusha
    call score1
    popa
    mov ah, 0ch
    int 21h
    RET

efface_ennemi_entier1:
    mov [bx-160], 0
    mov [bx-159], 0
    mov [bx-162], 0
    mov [bx-161], 0
    mov [bx-164], 0
    mov [bx-163], 0
    mov [bx-158], 0
    mov [bx-157], 0
    mov [bx-156], 0
    mov [bx-155], 0
    mov [bx], 0
    mov dh, 0
    sub cx, 1
    mov ah, 0ch
    pusha
    call score1
    popa
    int 21h
    RET
    
efface_bordure1:
    mov [bx], 0
    mov dh, 0
    mov ah, 0ch
    int 21h   
    RET 
    
efface_bordure_ennemi1:
    mov [bx], 0
    mov [bx+1], 0
    mov al, 0
    RET
    
casse_abri1:
    mov [bx-160], 0
    mov [bx-159], 0
    mov [bx], 0
    mov dh, 0
    mov ah, 0ch
    int 21h
    RET
    
efface_abri_ennemi1:
    mov [bx], 0
    mov [bx+1], 0
    mov [bx+160], 0
    mov [bx+161], 0
    mov al, 0  
    RET 
    
efface_missile0_1:
    mov [bx], 0
    mov [bx+160], 0
    mov [bx+1], 0
    mov dh, 0
    mov al, 0
    RET
    
efface_missile1_1:
    mov [bx], 0
    mov [bx-160], 0
    mov [bx-161], 0
    mov dh, 0 
    mov al, 0
    mov ah, 0ch
    int 21h
    RET
    
tire_test1:
    cmp dh, 1
    jne tire 
    mov ah, 0ch
    int 21h
    RET

value_ennemi1:
    mov bx, 2238
    RET
    
deplacement_droite0_1:
    cmp [bx], 'O'
    je deplacement_droite1_1
    sub bx, 2
    RET
    
deplacement_gauche0_1:
    cmp [bx], 'O'
    je deplacement_gauche1_1
    sub bx, 2
    RET
        
deplacement_droite1_1:
    cmp [bx+10], 0B1h
    je changedl1
    mov [bx-4], 0
    mov [bx-2], '('
    mov [bx-1], 1100b
    mov [bx], '-'
    mov [bx+1], 1100b
    mov [bx+2], 'O'
    mov [bx+3], 1100b
    mov [bx+4], '-'
    mov [bx+5], 1100b
    mov [bx+6], ')'
    mov [bx+7], 1100b
    sub bx, 12    
    RET
    
deplacement_gauche1_1:
    mov [bx+4], 0
    mov [bx+2], ')'
    mov [bx+1], 1100b
    mov [bx], '-'
    mov [bx-1], 1100b
    mov [bx-2], 'O'
    mov [bx-3], 1100b
    mov [bx-4], '-'
    mov [bx-5], 1100b
    mov [bx-6], '('
    mov [bx-7], 1100b
    cmp [bx-10], 0B1h
    je changedl0
    sub bx, 12
    RET
    
   

affichage_niveau2:
pusha
XOR AX, AX 
XOR BX, BX 
XOR CX, CX
XOR DX, DX
mov ah, 6
mov dx, 174fh
int 10h
popa
    
mov ah, 0ch
int 21h

mov bx, 0
mov cx, 79  

bordureh2:
mov [bx], 0B1h 
mov [bx+1], 00001110b
add bx, 2 
loop bordureh2

GOTOXY 1, 0
print 'Score:10'

mov bx, 0
mov cx, 25
bordureg2:
mov [bx], 0B1h 
mov [bx+1], 00001110b 
add bx, 160
loop bordureg2
XOR BX, BX

mov bx, 158
mov cx, 25
bordured2:
mov [bx], 0B1h 
mov [bx+1], 00001110b 
add bx, 160
loop bordured2
             
mov cx, 2
mov bx, 1142

ennemis2:
push cx
mov cx, 10
 
ligne_ennemis2:
mov [bx], '('
mov [bx+1], 1100b
mov [bx+2], '-'
mov [bx+3], 1100b
mov [bx+4], 'O'
mov [bx+5], 1100b
mov [bx+6], '-'      
mov [bx+7], 1100b
mov [bx+8], ')'      
mov [bx+9], 1100b
add bx, 12
loop ligne_ennemis2 

pop cx
add bx, 840 
loop ennemis2

mov bx, 3388
push bx
mov cx, 4

abri0_2:
mov [bx-1], 11101110b
mov [bx-2], 'D'
mov [bx+1], 11101110b
mov [bx], 'D'
mov [bx+9], 11101110b
mov [bx+8], 'D' 
mov [bx+11], 11101110b
mov [bx+10], 'D'
add bx, 32
loop abri0_2

pop bx
sub bx, 160
push bx
mov cx, 4

abri1_2:
mov [bx-1], 11101110b
mov [bx-2], 'D'
mov [bx+1], 11101110b
mov [bx], 'D'
mov [bx+3], 11101110b
mov [bx+2], 'D'
mov [bx+7], 11101110b
mov [bx+6], 'D'
mov [bx+9], 11101110b
mov [bx+8], 'D' 
mov [bx+11], 11101110b
mov [bx+10], 'D'
add bx, 32
loop abri1_2 
    
pop bx
sub bx, 160
push bx
mov cx, 4

abri2_2:
mov [bx-1], 11101110b
mov [bx-2], 'D'
mov [bx+1], 11101110b
mov [bx], 'D'
mov [bx+3], 11101110b
mov [bx+2], 'D'
mov [bx+5], 11101110b
mov [bx+4], 'D'
mov [bx+7], 11101110b
mov [bx+6], 'D'
mov [bx+9], 11101110b
mov [bx+8], 'D'
mov [bx+10], 'D'
mov [bx+11], 11101110b
add bx, 32
loop abri2_2 

mov bx, 3842 
mov cx, 78

bordurebas2:
mov [bx], 2Eh
mov [bx+1], 0000b
add bx, 2
loop bordurebas2

XOR BX, BX

mov di, 3918
mov bx, 3918
mov cx, 0
mov [bx-2], '>'
mov [bx-1], 1011b
mov [bx], 0E2h
mov [bx+1], 1011b
mov [bx+2], '<'
mov [bx+3], 1011b

mov cx, 20
mov ax, 0

main2:
push bx
call allie2
pop bx 
call ennemi2
call test_nbennemi2
loop main2   

;----->Commencement PROCEDURE<-----

allie2 PROC
    push ax
    call deplacement_allie2
    call tire_allie2 
    pop ax
    RET
allie2 ENDP
     
ennemi2 PROC 
    call deplacement_ennemi2
    push bx 
    call tire_ennemi2 
    pop bx  
    RET
ennemi2 ENDP

test_nbennemi2 PROC
    cmp cx, 0
    je affichage_niveau3
    add cx, 1
    RET
test_nbennemi2 ENDP

score2 PROC 
    GOTOXY 7, 0
    sub cx, 20  
    mov ax, cx
    neg ax
    add ax, 10   
    CALL print_num      ; print number in AX.
    RET                   ; return to operating system 
score2 ENDP

deplacement_allie2 PROC
    mov ah, 1
    int 16h
    cmp ah, 0x4bh
    je deplacementg2
    cmp ah, 0x4dh
    je deplacementd2
    RET
deplacement_allie2 ENDP

deplacement_ennemi2 PROC
    cmp bx, 2080
    jl value_ennemi2
    cmp bx, 2240
    ja value_ennemi2
    cmp dl, 0
    je deplacement_droite0_2   
    cmp dl, 1
    je deplacement_gauche0_2
    RET
deplacement_ennemi2 ENDP

tire_allie2 PROC
    mov ah, 1
    int 16h
    cmp ah, 0x48h
    je tire_test2
    cmp dh, 1
    je tire_deplacement2
    RET
tire_allie2 ENDP

tire_ennemi2 PROC
    call test_bx
    cmp al, 0
    jne deplacement_tire_ennemi2 
    RET
tire_ennemi2 ENDP  

test_bx2 PROC
    cmp [bx], 'O'
    je test_lancement_tire_ennemi2
    RET  
test_bx2 ENDP

;----->Fin PROCEDURE<-----

deplacementg2:
    mov bx, di
    cmp [bx-4], 2Eh
    jne deplacementd2
    mov [bx+2], 2Eh
    mov [bx+3], 0000b
    mov [bx], '<'
    mov [bx+1], 1011b
    sub bx, 2
    mov [bx], 0E2h
    mov [bx+1], 1011b
    mov [bx-2], '>'
    mov [bx-1], 1011b
    mov di, bx
    mov ah, 0ch
    int 21h
    RET
    

            
deplacementd2:
    mov bx, di
    cmp [bx+4], 2Eh
    jne deplacementg2 
    mov [bx-2], 2Eh
    mov [bx-1], 0000b
    mov [bx], '>'
    mov [bx+1], 1011b
    add bx, 2
    mov [bx], 0E2h
    mov [bx+1], 1011b
    mov [bx+2], '<'
    mov [bx+3], 1011b
    mov di, bx
    mov ah, 0ch
    int 21h
    RET

test_lancement_tire_ennemi2:
    cmp al, 0  
    je lancement_tire_ennemi2 
    sub al, 1  
    RET
lancement_tire_ennemi2:
    mov al, 9
    mov [bx+160], 0FEh
    mov [bx+161], 0100b
    add bx, 160 
    mov bp, bx
    RET   
    
deplacement_tire_ennemi2:
    mov bx, bp 
    cmp [bx+160], 0FEh
    je efface_missile0_2
    add bx, 160
    mov [bx-160], 0
    mov [bx], 0FEh
    mov [bx+1], 0100b
    cmp [bx+160], 'D'
    je efface_abri_ennemi2
    cmp [bx+160], 2Eh
    je efface_bordure_ennemi2  
    cmp [bx+160], '<'
    je fin_partie  
    cmp [bx+160], '>'
    je fin_partie 
    cmp [bx+160], 0E2h
    je fin_partie 
    mov bp, bx
    RET
    
tire2:
    mov dh, 1
    mov si, di
    sub si, 160
    mov bx, si
    mov [bx], 0FEh
    mov [bx+1], 1111b
    mov si, bx
    mov ah, 0ch
    int 21h
    RET
    
tire_deplacement2:
    mov bx, si
    sub bx, 160
    mov [bx], 0FEh
    mov [bx+1], 1111b 
    mov [bx+160], 0     
    cmp [bx-160], 'D'
    je casse_abri2
    cmp [bx-160], 'O'
    je efface_ennemi_entier2
    cmp [bx-162], '('
    je efface_ennemi_tiret_gauche2
    cmp [bx-158], ')'
    je efface_ennemi_tiret_droite2
    cmp [bx-162], '-'
    je efface_ennemi_droite2
    cmp [bx-158], '-'
    je efface_ennemi_gauche2
    cmp [bx-160], 0B1h
    je efface_bordure2
    cmp [bx-160], 0FEh
    je efface_missile1_2 
    mov si, bx
    RET 

efface_ennemi_tiret_droite2:
    mov [bx-168], 0
    mov [bx-167], 0
    mov [bx-166], 0
    mov [bx-165], 0 
    mov [bx-164], 0
    mov [bx-163], 0
    mov [bx-162], 0
    mov [bx-161], 0
    mov [bx-160], 0
    mov [bx-159], 0
    mov [bx-158], 0
    mov [bx-157], 0
    mov [bx], 0
    mov dh, 0
    sub cx, 1 
    pusha
    call score2
    popa
    mov ah, 0ch
    int 21h
    RET
    
efface_ennemi_tiret_gauche2:
    mov [bx-160], 0
    mov [bx-159], 0
    mov [bx-162], 0
    mov [bx-161], 0
    mov [bx-158], 0
    mov [bx-157], 0
    mov [bx-156], 0
    mov [bx-155], 0
    mov [bx-154], 0
    mov [bx-153], 0
    mov [bx], 0
    mov dh, 0
    sub cx, 1 
    pusha
    call score2
    popa
    mov ah, 0ch
    int 21h
    RET
    

efface_ennemi_droite2:
    mov [bx-168], 0
    mov [bx-167], 0
    mov [bx-166], 0
    mov [bx-165], 0 
    mov [bx-164], 0
    mov [bx-163], 0
    mov [bx-162], 0
    mov [bx-161], 0
    mov [bx-160], 0
    mov [bx-159], 0
    mov [bx], 0
    mov dh, 0
    sub cx, 1
    pusha
    call score2
    popa
    mov ah, 0ch
    int 21h
    RET

efface_ennemi_gauche2:
    mov [bx-160], 0
    mov [bx-159], 0
    mov [bx-158], 0
    mov [bx-157], 0
    mov [bx-156], 0
    mov [bx-155], 0
    mov [bx-154], 0
    mov [bx-153], 0
    mov [bx-152], 0
    mov [bx-151], 0
    mov [bx], 0
    mov dh, 0 
    sub cx, 1
    pusha
    call score2
    popa
    mov ah, 0ch
    int 21h
    RET

efface_ennemi_entier2:
    mov [bx-160], 0
    mov [bx-159], 0
    mov [bx-162], 0
    mov [bx-161], 0
    mov [bx-164], 0
    mov [bx-163], 0
    mov [bx-158], 0
    mov [bx-157], 0
    mov [bx-156], 0
    mov [bx-155], 0
    mov [bx], 0
    mov dh, 0
    sub cx, 1
    mov ah, 0ch
    pusha
    call score2
    popa
    int 21h
    RET
    
efface_bordure2:
    mov [bx], 0
    mov dh, 0
    mov ah, 0ch
    int 21h   
    RET 
    
efface_bordure_ennemi2:
    mov [bx], 0
    mov [bx+1], 0
    mov al, 0
    RET
    
casse_abri2:
    mov [bx-160], 0
    mov [bx-159], 0
    mov [bx], 0
    mov dh, 0
    mov ah, 0ch
    int 21h
    RET
    
efface_abri_ennemi2:
    mov [bx], 0
    mov [bx+1], 0
    mov [bx+160], 0
    mov [bx+161], 0
    mov al, 0  
    RET 
    
efface_missile0_2:
    mov [bx], 0
    mov [bx+160], 0
    mov [bx+1], 0
    mov dh, 0
    mov al, 0
    RET
    
efface_missile1_2:
    mov [bx], 0
    mov [bx-160], 0
    mov [bx-161], 0
    mov dh, 0 
    mov al, 0
    mov ah, 0ch
    int 21h
    RET
    
tire_test2:
    cmp dh, 1
    jne tire 
    mov ah, 0ch
    int 21h
    RET

value_ennemi2:
    mov bx, 2238
    RET
    
deplacement_droite0_2:
    cmp [bx], 'O'
    je deplacement_droite1_2
    cmp [bx-960], 'O'
    je deplacement_droite2_2
    sub bx, 2
    RET
    
deplacement_gauche0_2:
    cmp [bx], 'O'
    je deplacement_gauche1_2
    cmp [bx-960], 'O'
    je deplacement_gauche2_2
    sub bx, 2
    RET
        
deplacement_droite1_2:
    cmp [bx+10], 0B1h
    je changedl1
    mov [bx-4], 0
    mov [bx-2], '('
    mov [bx-1], 1100b
    mov [bx], '-'
    mov [bx+1], 1100b
    mov [bx+2], 'O'
    mov [bx+3], 1100b
    mov [bx+4], '-'
    mov [bx+5], 1100b
    mov [bx+6], ')'
    mov [bx+7], 1100b
    
    mov [bx-964], 0
    mov [bx-962], '('
    mov [bx-961], 1100b
    mov [bx-960], '-'
    mov [bx-959], 1100b
    mov [bx-958], 'O'
    mov [bx-957], 1100b
    mov [bx-956], '-'
    mov [bx-955], 1100b
    mov [bx-954], ')'
    mov [bx-953], 1100b
    RET
    
deplacement_droite2_2:
    cmp [bx+10], 0B1h
    je changedl1
    mov [bx-964], 0
    mov [bx-962], '('
    mov [bx-961], 1100b
    mov [bx-960], '-'
    mov [bx-959], 1100b
    mov [bx-958], 'O'
    mov [bx-957], 1100b
    mov [bx-956], '-'
    mov [bx-955], 1100b
    mov [bx-954], ')'
    mov [bx-953], 1100b
    RET
    
deplacement_gauche1_2:
    mov [bx+4], 0
    mov [bx+2], ')'
    mov [bx+1], 1100b
    mov [bx], '-'
    mov [bx-1], 1100b
    mov [bx-2], 'O'
    mov [bx-3], 1100b
    mov [bx-4], '-'
    mov [bx-5], 1100b
    mov [bx-6], '('
    mov [bx-7], 1100b
    
    mov [bx-956], 0
    mov [bx-958], ')'
    mov [bx-959], 1100b
    mov [bx-960], '-'
    mov [bx-961], 1100b
    mov [bx-962], 'O'
    mov [bx-963], 1100b
    mov [bx-964], '-'
    mov [bx-965], 1100b
    mov [bx-966], '('
    mov [bx-967], 1100b
    cmp [bx-10], 0B1h
    je changedl0
    sub bx, 12
    RET
    
deplacement_gauche2_2:
    mov [bx-956], 0
    mov [bx-958], ')'
    mov [bx-959], 1100b
    mov [bx-960], '-'
    mov [bx-961], 1100b
    mov [bx-962], 'O'
    mov [bx-963], 1100b
    mov [bx-964], '-'
    mov [bx-965], 1100b
    mov [bx-966], '('
    mov [bx-967], 1100b 
    cmp [bx-10], 0B1h
    je changedl0
    sub bx, 12
    RET
    


affichage_niveau3:
pusha
XOR AX, AX 
XOR BX, BX 
XOR CX, CX
XOR DX, DX
mov ah, 6
mov dx, 174fh
int 10h
popa
    
mov ah, 0ch
int 21h

mov bx, 0
mov cx, 79  

bordureh3:
mov [bx], 0B1h 
mov [bx+1], 00001110b
add bx, 2 
loop bordureh3

GOTOXY 1, 0
print 'Score:30'

mov bx, 0
mov cx, 25
bordureg3:
mov [bx], 0B1h 
mov [bx+1], 00001110b 
add bx, 160
loop bordureg3
XOR BX, BX

mov bx, 158
mov cx, 25
bordured3:
mov [bx], 0B1h 
mov [bx+1], 00001110b 
add bx, 160
loop bordured3

mov cx, 3
mov bx, 1142

ennemis3:
push cx
mov cx, 10
 
ligne_ennemis3:
mov [bx], '('
mov [bx+1], 1100b
mov [bx+2], '-'
mov [bx+3], 1100b
mov [bx+4], 'O'
mov [bx+5], 1100b
mov [bx+6], '-'      
mov [bx+7], 1100b
mov [bx+8], ')'      
mov [bx+9], 1100b
add bx, 12
loop ligne_ennemis3 

pop cx
add bx, 360
loop ennemis3

mov bx, 3388
push bx
mov cx, 4

abri0_3:
mov [bx-1], 11101110b
mov [bx-2], 'D'
mov [bx+1], 11101110b
mov [bx], 'D'
mov [bx+9], 11101110b
mov [bx+8], 'D' 
mov [bx+11], 11101110b
mov [bx+10], 'D'
add bx, 32
loop abri0_3

pop bx
sub bx, 160
push bx
mov cx, 4

abri1_3:
mov [bx-1], 11101110b
mov [bx-2], 'D'
mov [bx+1], 11101110b
mov [bx], 'D'
mov [bx+3], 11101110b
mov [bx+2], 'D'
mov [bx+7], 11101110b
mov [bx+6], 'D'
mov [bx+9], 11101110b
mov [bx+8], 'D' 
mov [bx+11], 11101110b
mov [bx+10], 'D'
add bx, 32
loop abri1_3 
    
pop bx
sub bx, 160
push bx
mov cx, 4

abri2_3:
mov [bx-1], 11101110b
mov [bx-2], 'D'
mov [bx+1], 11101110b
mov [bx], 'D'
mov [bx+3], 11101110b
mov [bx+2], 'D'
mov [bx+5], 11101110b
mov [bx+4], 'D'
mov [bx+7], 11101110b
mov [bx+6], 'D'
mov [bx+9], 11101110b
mov [bx+8], 'D'
mov [bx+10], 'D'
mov [bx+11], 11101110b
add bx, 32
loop abri2_3 

mov bx, 3842 
mov cx, 78

bordurebas3:
mov [bx], 2Eh
mov [bx+1], 0000b
add bx, 2
loop bordurebas3

XOR BX, BX

mov di, 3918
mov bx, 3918
mov cx, 0
mov [bx-2], '>'
mov [bx-1], 1011b
mov [bx], 0E2h
mov [bx+1], 1011b
mov [bx+2], '<'
mov [bx+3], 1011b

mov cx, 30
mov ax, 0

main3:
push bx
call allie3
pop bx 
call ennemi3
call test_nbennemi3
loop main3   

;----->Commencement PROCEDURE<-----

allie3 PROC
    push ax
    call deplacement_allie3
    call tire_allie3 
    pop ax
    RET
allie3 ENDP

ennemi3 PROC 
    call deplacement_ennemi3
    push bx 
    call tire_ennemi3 
    pop bx  
    RET
ennemi3 ENDP

test_nbennemi3 PROC
    cmp cx, 0
    je affichage_niveau4
    add cx, 1
    RET
test_nbennemi3 ENDP

score3 PROC 
    GOTOXY 7, 0
    sub cx, 30  
    mov ax, cx
    neg ax
    add ax, 30 
    
    CALL print_num      ; print number in AX.
    RET                   ; return to operating system 
score3 ENDP

deplacement_allie3 PROC
    mov ah, 1
    int 16h
    cmp ah, 0x4bh
    je deplacementg3
    cmp ah, 0x4dh
    je deplacementd3
    RET
deplacement_allie3 ENDP

deplacement_ennemi3 PROC
    cmp bx, 2080
    jl value_ennemi3
    cmp bx, 2240
    ja value_ennemi3
    cmp dl, 0
    je deplacement_droite0_3   
    cmp dl, 1
    je deplacement_gauche0_3
    RET
deplacement_ennemi3 ENDP

tire_allie3 PROC
    mov ah, 1
    int 16h
    cmp ah, 0x48h
    je tire_test3
    cmp dh, 1
    je tire_deplacement3
    RET
tire_allie3 ENDP

tire_ennemi3 PROC
    call test_bx
    cmp al, 0
    jne deplacement_tire_ennemi3 
    RET
tire_ennemi3 ENDP  

test_bx3 PROC
    cmp [bx], 'O'
    je test_lancement_tire_ennemi3
    RET  
test_bx3 ENDP

;----->Fin PROCEDURE<-----

deplacementg3:
    mov bx, di
    cmp [bx-4], 2Eh
    jne deplacementd3
    mov [bx+2], 2Eh
    mov [bx+3], 0000b
    mov [bx], '<'
    mov [bx+1], 1011b
    sub bx, 2
    mov [bx], 0E2h
    mov [bx+1], 1011b
    mov [bx-2], '>'
    mov [bx-1], 1011b
    mov di, bx
    mov ah, 0ch
    int 21h
    RET
                
deplacementd3:
    mov bx, di
    cmp [bx+4], 2Eh
    jne deplacementg3 
    mov [bx-2], 2Eh
    mov [bx-1], 0000b
    mov [bx], '>'
    mov [bx+1], 1011b
    add bx, 2
    mov [bx], 0E2h
    mov [bx+1], 1011b
    mov [bx+2], '<'
    mov [bx+3], 1011b
    mov di, bx
    mov ah, 0ch
    int 21h
    RET

test_lancement_tire_ennemi3:
    cmp al, 0  
    je lancement_tire_ennemi3 
    sub al, 1  
    RET
lancement_tire_ennemi3:
    mov al, 9
    mov [bx+160], 0FEh
    mov [bx+161], 0100b
    add bx, 160 
    mov bp, bx
    RET   
    
deplacement_tire_ennemi3:
    mov bx, bp 
    cmp [bx+160], 0FEh
    je efface_missile0_3
    add bx, 160
    mov [bx-160], 0
    mov [bx], 0FEh
    mov [bx+1], 0100b
    cmp [bx+160], 'D'
    je efface_abri_ennemi3
    cmp [bx+160], 2Eh
    je efface_bordure_ennemi3  
    cmp [bx+160], '<'
    je fin_partie  
    cmp [bx+160], '>'
    je fin_partie 
    cmp [bx+160], 0E2h
    je fin_partie 
    mov bp, bx
    RET
    
tire3:
    mov dh, 1
    mov si, di
    sub si, 160
    mov bx, si
    mov [bx], 0FEh
    mov [bx+1], 1111b
    mov si, bx
    mov ah, 0ch
    int 21h
    RET
    
tire_deplacement3:
    mov bx, si
    sub bx, 160
    mov [bx], 0FEh
    mov [bx+1], 1111b 
    mov [bx+160], 0     
    cmp [bx-160], 'D'
    je casse_abri
    cmp [bx-160], 'O'
    je efface_ennemi_entier3
    cmp [bx-162], '('
    je efface_ennemi_tiret_gauche3
    cmp [bx-158], ')'
    je efface_ennemi_tiret_droite3
    cmp [bx-162], '-'
    je efface_ennemi_droite3
    cmp [bx-158], '-'
    je efface_ennemi_gauche3
    cmp [bx-160], 0B1h
    je efface_bordure3
    cmp [bx-160], 0FEh
    je efface_missile1_3 
    mov si, bx
    RET 

efface_ennemi_tiret_droite3:
    mov [bx-168], 0
    mov [bx-167], 0
    mov [bx-166], 0
    mov [bx-165], 0 
    mov [bx-164], 0
    mov [bx-163], 0
    mov [bx-162], 0
    mov [bx-161], 0
    mov [bx-160], 0
    mov [bx-159], 0
    mov [bx-158], 0
    mov [bx-157], 0
    mov [bx], 0
    mov dh, 0
    sub cx, 1 
    pusha
    call score3
    popa
    mov ah, 0ch
    int 21h
    RET
    
efface_ennemi_tiret_gauche3:
    mov [bx-160], 0
    mov [bx-159], 0
    mov [bx-162], 0
    mov [bx-161], 0
    mov [bx-158], 0
    mov [bx-157], 0
    mov [bx-156], 0
    mov [bx-155], 0
    mov [bx-154], 0
    mov [bx-153], 0
    mov [bx], 0
    mov dh, 0
    sub cx, 1 
    pusha
    call score3
    popa
    mov ah, 0ch
    int 21h
    RET
    

efface_ennemi_droite3:
    mov [bx-168], 0
    mov [bx-167], 0
    mov [bx-166], 0
    mov [bx-165], 0 
    mov [bx-164], 0
    mov [bx-163], 0
    mov [bx-162], 0
    mov [bx-161], 0
    mov [bx-160], 0
    mov [bx-159], 0
    mov [bx], 0
    mov dh, 0
    sub cx, 1
    pusha
    call score3
    popa
    mov ah, 0ch
    int 21h
    RET

efface_ennemi_gauche3:
    mov [bx-160], 0
    mov [bx-159], 0
    mov [bx-158], 0
    mov [bx-157], 0
    mov [bx-156], 0
    mov [bx-155], 0
    mov [bx-154], 0
    mov [bx-153], 0
    mov [bx-152], 0
    mov [bx-151], 0
    mov [bx], 0
    mov dh, 0 
    sub cx, 1
    pusha
    call score3
    popa
    mov ah, 0ch
    int 21h
    RET

efface_ennemi_entier3:
    mov [bx-160], 0
    mov [bx-159], 0
    mov [bx-162], 0
    mov [bx-161], 0
    mov [bx-164], 0
    mov [bx-163], 0
    mov [bx-158], 0
    mov [bx-157], 0
    mov [bx-156], 0
    mov [bx-155], 0
    mov [bx], 0
    mov dh, 0
    sub cx, 1
    mov ah, 0ch
    pusha
    call score3
    popa
    int 21h
    RET
    
efface_bordure3:
    mov [bx], 0
    mov dh, 0
    mov ah, 0ch
    int 21h   
    RET 
    
efface_bordure_ennemi3:
    mov [bx], 0
    mov [bx+1], 0
    mov al, 0
    RET
    
casse_abri3:
    mov [bx-160], 0
    mov [bx-159], 0
    mov [bx], 0
    mov dh, 0
    mov ah, 0ch
    int 21h
    RET
    
efface_abri_ennemi3:
    mov [bx], 0
    mov [bx+1], 0
    mov [bx+160], 0
    mov [bx+161], 0
    mov al, 0  
    RET 
    
efface_missile0_3:
    mov [bx], 0
    mov [bx+160], 0
    mov [bx+1], 0
    mov dh, 0
    mov al, 0
    RET
    
efface_missile1_3:
    mov [bx], 0
    mov [bx-160], 0
    mov [bx-161], 0
    mov dh, 0 
    mov al, 0
    mov ah, 0ch
    int 21h
    RET
    
tire_test3:
    cmp dh, 1
    jne tire 
    mov ah, 0ch
    int 21h
    RET

value_ennemi3:
    mov bx, 2238
    RET
    
deplacement_droite0_3:
    cmp [bx], 'O'
    je deplacement_droite1_3
    cmp [bx-480], 'O'
    je deplacement_droite2_3
    cmp [bx-960], 'O'
    je deplacement_droite3_3
    sub bx, 2
    RET
    
deplacement_gauche0_3:
    cmp [bx], 'O'
    je deplacement_gauche1_3
    cmp [bx-480], 'O'
    je deplacement_gauche2_3
    cmp [bx-960], 'O'
    je deplacement_gauche3_3
    sub bx, 2
    RET
        
deplacement_droite1_3:
    cmp [bx+10], 0B1h
    je changedl1
    mov [bx-4], 0
    mov [bx-2], '('
    mov [bx-1], 1100b
    mov [bx], '-'
    mov [bx+1], 1100b
    mov [bx+2], 'O'
    mov [bx+3], 1100b
    mov [bx+4], '-'
    mov [bx+5], 1100b
    mov [bx+6], ')'
    mov [bx+7], 1100b
    
    mov [bx-484], 0
    mov [bx-482], '('
    mov [bx-481], 1100b
    mov [bx-480], '-'
    mov [bx-479], 1100b
    mov [bx-478], 'O'
    mov [bx-477], 1100b
    mov [bx-476], '-'
    mov [bx-475], 1100b
    mov [bx-474], ')'
    mov [bx-473], 1100b
    
    mov [bx-964], 0
    mov [bx-962], '('
    mov [bx-961], 1100b
    mov [bx-960], '-'
    mov [bx-959], 1100b
    mov [bx-958], 'O'
    mov [bx-957], 1100b
    mov [bx-956], '-'
    mov [bx-955], 1100b
    mov [bx-954], ')'
    mov [bx-953], 1100b
    sub bx, 12    
    RET
    
deplacement_droite2_3:
    cmp [bx+10], 0B1h
    je changedl1
    mov [bx-484], 0
    mov [bx-482], '('
    mov [bx-481], 1100b
    mov [bx-480], '-'
    mov [bx-479], 1100b
    mov [bx-478], 'O'
    mov [bx-477], 1100b
    mov [bx-476], '-'
    mov [bx-475], 1100b
    mov [bx-474], ')'
    mov [bx-473], 1100b
    
    mov [bx-964], 0
    mov [bx-962], '('
    mov [bx-961], 1100b
    mov [bx-960], '-'
    mov [bx-959], 1100b
    mov [bx-958], 'O'
    mov [bx-957], 1100b
    mov [bx-956], '-'
    mov [bx-955], 1100b
    mov [bx-954], ')'
    mov [bx-953], 1100b
    sub bx, 12    
    RET
    
deplacement_droite3_3:
    cmp [bx+10], 0B1h
    je changedl1   
    mov [bx-964], 0
    mov [bx-962], '('
    mov [bx-961], 1100b
    mov [bx-960], '-'
    mov [bx-959], 1100b
    mov [bx-958], 'O'
    mov [bx-957], 1100b
    mov [bx-956], '-'
    mov [bx-955], 1100b
    mov [bx-954], ')'
    mov [bx-953], 1100b
    sub bx, 12    
    RET
    
deplacement_gauche1_3:
    mov [bx+4], 0
    mov [bx+2], ')'
    mov [bx+1], 1100b
    mov [bx], '-'
    mov [bx-1], 1100b
    mov [bx-2], 'O'
    mov [bx-3], 1100b
    mov [bx-4], '-'
    mov [bx-5], 1100b
    mov [bx-6], '('
    mov [bx-7], 1100b
    
    mov [bx-476], 0
    mov [bx-478], ')'
    mov [bx-479], 1100b
    mov [bx-480], '-'
    mov [bx-481], 1100b
    mov [bx-482], 'O'
    mov [bx-483], 1100b
    mov [bx-484], '-'
    mov [bx-485], 1100b
    mov [bx-486], '('
    mov [bx-487], 1100b
    
    mov [bx-956], 0
    mov [bx-958], ')'
    mov [bx-959], 1100b
    mov [bx-960], '-'
    mov [bx-961], 1100b
    mov [bx-962], 'O'
    mov [bx-963], 1100b
    mov [bx-964], '-'
    mov [bx-965], 1100b
    mov [bx-966], '('
    mov [bx-967], 1100b
    cmp [bx-10], 0B1h
    je changedl0
    sub bx, 12
    RET
    
deplacement_gauche2_3:
    mov [bx-476], 0
    mov [bx-478], ')'
    mov [bx-479], 1100b
    mov [bx-480], '-'
    mov [bx-481], 1100b
    mov [bx-482], 'O'
    mov [bx-483], 1100b
    mov [bx-484], '-'
    mov [bx-485], 1100b
    mov [bx-486], '('
    mov [bx-487], 1100b
    
    mov [bx-956], 0
    mov [bx-958], ')'
    mov [bx-959], 1100b
    mov [bx-960], '-'
    mov [bx-961], 1100b
    mov [bx-962], 'O'
    mov [bx-963], 1100b
    mov [bx-964], '-'
    mov [bx-965], 1100b
    mov [bx-966], '('
    mov [bx-967], 1100b
    cmp [bx-10], 0B1h
    je changedl0
    sub bx, 12
    RET
    
deplacement_gauche3_3:
    mov [bx-956], 0
    mov [bx-958], ')'
    mov [bx-959], 1100b
    mov [bx-960], '-'
    mov [bx-961], 1100b
    mov [bx-962], 'O'
    mov [bx-963], 1100b
    mov [bx-964], '-'
    mov [bx-965], 1100b
    mov [bx-966], '('
    mov [bx-967], 1100b
    cmp [bx-10], 0B1h
    je changedl0
    sub bx, 12
    RET
          
    
affichage_niveau4:
pusha
XOR AX, AX 
XOR BX, BX 
XOR CX, CX
XOR DX, DX
mov ah, 6
mov dx, 174fh
int 10h
popa
    
mov ah, 0ch
int 21h

mov bx, 0
mov cx, 79  

bordureh:
mov [bx], 0B1h 
mov [bx+1], 00001110b
add bx, 2 
loop bordureh

GOTOXY 1, 0
print 'Score:60'

mov bx, 0
mov cx, 25
bordureg:
mov [bx], 0B1h 
mov [bx+1], 00001110b 
add bx, 160
loop bordureg
XOR BX, BX

mov bx, 158
mov cx, 25
bordured:
mov [bx], 0B1h 
mov [bx+1], 00001110b 
add bx, 160
loop bordured

mov cx, 4
mov bx, 662

ennemis:
push cx
mov cx, 10
 
ligne_ennemis:
mov [bx], '('
mov [bx+1], 1100b
mov [bx+2], '-'
mov [bx+3], 1100b
mov [bx+4], 'O'
mov [bx+5], 1100b
mov [bx+6], '-'      
mov [bx+7], 1100b
mov [bx+8], ')'      
mov [bx+9], 1100b
add bx, 12
loop ligne_ennemis 

pop cx
add bx, 360
loop ennemis

mov bx, 3388
push bx
mov cx, 4

abri:
mov [bx-1], 11101110b
mov [bx-2], 'D'
mov [bx+1], 11101110b
mov [bx], 'D'
mov [bx+9], 11101110b
mov [bx+8], 'D' 
mov [bx+11], 11101110b
mov [bx+10], 'D'
add bx, 32
loop abri

pop bx
sub bx, 160
push bx
mov cx, 4

abri1:
mov [bx-1], 11101110b
mov [bx-2], 'D'
mov [bx+1], 11101110b
mov [bx], 'D'
mov [bx+3], 11101110b
mov [bx+2], 'D'
mov [bx+7], 11101110b
mov [bx+6], 'D'
mov [bx+9], 11101110b
mov [bx+8], 'D' 
mov [bx+11], 11101110b
mov [bx+10], 'D'
add bx, 32
loop abri1 
    
pop bx
sub bx, 160
push bx
mov cx, 4

abri2:
mov [bx-1], 11101110b
mov [bx-2], 'D'
mov [bx+1], 11101110b
mov [bx], 'D'
mov [bx+3], 11101110b
mov [bx+2], 'D'
mov [bx+5], 11101110b
mov [bx+4], 'D'
mov [bx+7], 11101110b
mov [bx+6], 'D'
mov [bx+9], 11101110b
mov [bx+8], 'D'
mov [bx+10], 'D'
mov [bx+11], 11101110b
add bx, 32
loop abri2 

mov bx, 3842 
mov cx, 78

bordurebas:
mov [bx], 2Eh
mov [bx+1], 0000b
add bx, 2
loop bordurebas

XOR BX, BX

mov di, 3918
mov bx, 3918
mov cx, 0
mov [bx-2], '>'
mov [bx-1], 1011b
mov [bx], 0E2h
mov [bx+1], 1011b
mov [bx+2], '<'
mov [bx+3], 1011b

mov cx, 40
mov ax, 0

main:
push bx
call allie
pop bx 
call ennemi
call test_nbennemi
loop main   

;----->Commencement PROCEDURE<-----

allie PROC
    push ax
    call deplacement_allie
    call tire_allie 
    pop ax
    RET
allie ENDP

ennemi PROC 
    call deplacement_ennemi
    push bx 
    call tire_ennemi 
    pop bx  
    RET
ennemi ENDP

test_nbennemi PROC
    cmp cx, 0
    je fin_partie
    add cx, 1
    RET
test_nbennemi ENDP

score4 PROC 
    GOTOXY 7, 0
    sub cx, 60  
    mov ax, cx
    neg ax
    add ax, 40 
    CALL print_num      ; print number in AX.
    RET                   ; return to operating system 
score4 ENDP

deplacement_allie PROC
    mov ah, 1
    int 16h
    cmp ah, 0x4bh
    je deplacementg
    cmp ah, 0x4dh
    je deplacementd
    RET
deplacement_allie ENDP

deplacement_ennemi PROC
    cmp bx, 2080
    jl value_ennemi
    cmp bx, 2240
    ja value_ennemi
    cmp dl, 0
    je deplacement_droite   
    cmp dl, 1
    je deplacement_gauche
    RET
deplacement_ennemi ENDP

tire_allie PROC
    mov ah, 1
    int 16h
    cmp ah, 0x48h
    je tire_test
    cmp dh, 1
    je tire_deplacement
    RET
tire_allie ENDP

tire_ennemi PROC
    call test_bx
    cmp al, 0
    jne deplacement_tire_ennemi 
    RET
tire_ennemi ENDP  

test_bx PROC
    cmp [bx], 'O'
    je test_lancement_tire_ennemi
    RET  
test_bx ENDP

;----->Fin PROCEDURE<-----

deplacementg:
    mov bx, di
    cmp [bx-4], 2Eh
    jne deplacementd
    mov [bx+2], 2Eh
    mov [bx+3], 0000b
    mov [bx], '<'
    mov [bx+1], 1011b
    sub bx, 2
    mov [bx], 0E2h
    mov [bx+1], 1011b
    mov [bx-2], '>'
    mov [bx-1], 1011b
    mov di, bx
    mov ah, 0ch
    int 21h
    RET
    

            
deplacementd:
    mov bx, di
    cmp [bx+4], 2Eh
    jne deplacementg 
    mov [bx-2], 2Eh
    mov [bx-1], 0000b
    mov [bx], '>'
    mov [bx+1], 1011b
    add bx, 2
    mov [bx], 0E2h
    mov [bx+1], 1011b
    mov [bx+2], '<'
    mov [bx+3], 1011b
    mov di, bx
    mov ah, 0ch
    int 21h
    RET

test_lancement_tire_ennemi:
    cmp al, 0  
    je lancement_tire_ennemi 
    sub al, 1  
    RET
lancement_tire_ennemi:
    mov al, 9
    mov [bx+160], 0FEh
    mov [bx+161], 0100b
    add bx, 160 
    mov bp, bx
    RET   
    
deplacement_tire_ennemi:
    mov bx, bp 
    cmp [bx+160], 0FEh
    je efface_missile0_4
    add bx, 160
    mov [bx-160], 0
    mov [bx], 0FEh
    mov [bx+1], 0100b
    cmp [bx+160], 'D'
    je efface_abri_ennemi
    cmp [bx+160], 2Eh
    je efface_bordure_ennemi  
    cmp [bx+160], '<'
    je fin_partie  
    cmp [bx+160], '>'
    je fin_partie 
    cmp [bx+160], 0E2h
    je fin_partie 
    mov bp, bx
    RET
    
tire:
    mov dh, 1
    mov si, di
    sub si, 160
    mov bx, si
    mov [bx], 0FEh
    mov [bx+1], 1111b
    mov si, bx
    mov ah, 0ch
    int 21h
    RET
    
tire_deplacement:
    mov bx, si
    sub bx, 160
    mov [bx], 0FEh
    mov [bx+1], 1111b 
    mov [bx+160], 0     
    cmp [bx-160], 'D'
    je casse_abri
    cmp [bx-160], 'O'
    je efface_ennemi_entier
    cmp [bx-162], '('
    je efface_ennemi_tiret_gauche
    cmp [bx-158], ')'
    je efface_ennemi_tiret_droite
    cmp [bx-162], '-'
    je efface_ennemi_droite
    cmp [bx-158], '-'
    je efface_ennemi_gauche
    cmp [bx-160], 0B1h
    je efface_bordure
    cmp [bx-160], 0FEh
    je efface_missile1_4 
    mov si, bx
    RET 

efface_ennemi_tiret_droite:
    mov [bx-168], 0
    mov [bx-167], 0
    mov [bx-166], 0
    mov [bx-165], 0 
    mov [bx-164], 0
    mov [bx-163], 0
    mov [bx-162], 0
    mov [bx-161], 0
    mov [bx-160], 0
    mov [bx-159], 0
    mov [bx-158], 0
    mov [bx-157], 0
    mov [bx], 0
    mov dh, 0
    sub cx, 1 
    pusha
    call score4
    popa
    mov ah, 0ch
    int 21h
    RET
    
efface_ennemi_tiret_gauche:
    mov [bx-160], 0
    mov [bx-159], 0
    mov [bx-162], 0
    mov [bx-161], 0
    mov [bx-158], 0
    mov [bx-157], 0
    mov [bx-156], 0
    mov [bx-155], 0
    mov [bx-154], 0
    mov [bx-153], 0
    mov [bx], 0
    mov dh, 0
    sub cx, 1 
    pusha
    call score4
    popa
    mov ah, 0ch
    int 21h
    RET
    

efface_ennemi_droite:
    mov [bx-168], 0
    mov [bx-167], 0
    mov [bx-166], 0
    mov [bx-165], 0 
    mov [bx-164], 0
    mov [bx-163], 0
    mov [bx-162], 0
    mov [bx-161], 0
    mov [bx-160], 0
    mov [bx-159], 0
    mov [bx], 0
    mov dh, 0
    sub cx, 1
    pusha
    call score4
    popa
    mov ah, 0ch
    int 21h
    RET

efface_ennemi_gauche:
    mov [bx-160], 0
    mov [bx-159], 0
    mov [bx-158], 0
    mov [bx-157], 0
    mov [bx-156], 0
    mov [bx-155], 0
    mov [bx-154], 0
    mov [bx-153], 0
    mov [bx-152], 0
    mov [bx-151], 0
    mov [bx], 0
    mov dh, 0 
    sub cx, 1
    pusha
    call score4
    popa
    mov ah, 0ch
    int 21h
    RET

efface_ennemi_entier:
    mov [bx-160], 0
    mov [bx-159], 0
    mov [bx-162], 0
    mov [bx-161], 0
    mov [bx-164], 0
    mov [bx-163], 0
    mov [bx-158], 0
    mov [bx-157], 0
    mov [bx-156], 0
    mov [bx-155], 0
    mov [bx], 0
    mov dh, 0
    sub cx, 1
    mov ah, 0ch
    pusha
    call score4
    popa
    int 21h
    RET
    
efface_bordure:
    mov [bx], 0
    mov dh, 0
    mov ah, 0ch
    int 21h   
    RET 
    
efface_bordure_ennemi:
    mov [bx], 0
    mov [bx+1], 0
    mov al, 0
    RET
    
casse_abri:
    mov [bx-160], 0
    mov [bx-159], 0
    mov [bx], 0
    mov dh, 0
    mov ah, 0ch
    int 21h
    RET
    
efface_abri_ennemi:
    mov [bx], 0
    mov [bx+1], 0
    mov [bx+160], 0
    mov [bx+161], 0
    mov al, 0  
    RET 
    
efface_missile0_4:
    mov [bx], 0
    mov [bx+160], 0
    mov [bx+1], 0
    mov dh, 0
    mov al, 0
    RET
    
efface_missile1_4:
    mov [bx], 0
    mov [bx-160], 0
    mov [bx-161], 0
    mov dh, 0 
    mov al, 0
    mov ah, 0ch
    int 21h
    RET
    
tire_test:
    cmp dh, 1
    jne tire 
    mov ah, 0ch
    int 21h
    RET

value_ennemi:
    mov bx, 2238
    RET
    
deplacement_droite:
    cmp [bx], 'O'
    je deplacement_droite1
    cmp [bx-480], 'O'
    je deplacement_droite2
    cmp [bx-960], 'O'
    je deplacement_droite3
    cmp [bx-1440], 'O'
    je deplacement_droite4
    sub bx, 2
    RET
    
deplacement_gauche:
    cmp [bx], 'O'
    je deplacement_gauche1
    cmp [bx-480], 'O'
    je deplacement_gauche2
    cmp [bx-960], 'O'
    je deplacement_gauche3
    cmp [bx-1440], 'O'
    je deplacement_gauche4
    sub bx, 2
    RET
        
deplacement_droite1:
    cmp [bx+10], 0B1h
    je changedl1
    mov [bx-4], 0
    mov [bx-2], '('
    mov [bx-1], 1100b
    mov [bx], '-'
    mov [bx+1], 1100b
    mov [bx+2], 'O'
    mov [bx+3], 1100b
    mov [bx+4], '-'
    mov [bx+5], 1100b
    mov [bx+6], ')'
    mov [bx+7], 1100b
    
    mov [bx-484], 0
    mov [bx-482], '('
    mov [bx-481], 1100b
    mov [bx-480], '-'
    mov [bx-479], 1100b
    mov [bx-478], 'O'
    mov [bx-477], 1100b
    mov [bx-476], '-'
    mov [bx-475], 1100b
    mov [bx-474], ')'
    mov [bx-473], 1100b
    
    mov [bx-964], 0
    mov [bx-962], '('
    mov [bx-961], 1100b
    mov [bx-960], '-'
    mov [bx-959], 1100b
    mov [bx-958], 'O'
    mov [bx-957], 1100b
    mov [bx-956], '-'
    mov [bx-955], 1100b
    mov [bx-954], ')'
    mov [bx-953], 1100b
    
    mov [bx-1444], 0
    mov [bx-1442], '('
    mov [bx-1441], 1100b
    mov [bx-1440], '-'
    mov [bx-1439], 1100b
    mov [bx-1438], 'O'
    mov [bx-1437], 1100b
    mov [bx-1436], '-'
    mov [bx-1435], 1100b
    mov [bx-1434], ')'
    mov [bx-1433], 1100b
    sub bx, 12    
    RET
    
deplacement_droite2:
    cmp [bx+10], 0B1h
    je changedl1
    mov [bx-484], 0
    mov [bx-482], '('
    mov [bx-481], 1100b
    mov [bx-480], '-'
    mov [bx-479], 1100b
    mov [bx-478], 'O'
    mov [bx-477], 1100b
    mov [bx-476], '-'
    mov [bx-475], 1100b
    mov [bx-474], ')'
    mov [bx-473], 1100b
    
    mov [bx-964], 0
    mov [bx-962], '('
    mov [bx-961], 1100b
    mov [bx-960], '-'
    mov [bx-959], 1100b
    mov [bx-958], 'O'
    mov [bx-957], 1100b
    mov [bx-956], '-'
    mov [bx-955], 1100b
    mov [bx-954], ')'
    mov [bx-953], 1100b
    
    mov [bx-1444], 0
    mov [bx-1442], '('
    mov [bx-1441], 1100b
    mov [bx-1440], '-'
    mov [bx-1439], 1100b
    mov [bx-1438], 'O'
    mov [bx-1437], 1100b
    mov [bx-1436], '-'
    mov [bx-1435], 1100b
    mov [bx-1434], ')'
    mov [bx-1433], 1100b
    sub bx, 12    
    RET
    
deplacement_droite3:
    cmp [bx+10], 0B1h
    je changedl1   
    mov [bx-964], 0
    mov [bx-962], '('
    mov [bx-961], 1100b
    mov [bx-960], '-'
    mov [bx-959], 1100b
    mov [bx-958], 'O'
    mov [bx-957], 1100b
    mov [bx-956], '-'
    mov [bx-955], 1100b
    mov [bx-954], ')'
    mov [bx-953], 1100b
    
    mov [bx-1444], 0
    mov [bx-1442], '('
    mov [bx-1441], 1100b
    mov [bx-1440], '-'
    mov [bx-1439], 1100b
    mov [bx-1438], 'O'
    mov [bx-1437], 1100b
    mov [bx-1436], '-'
    mov [bx-1435], 1100b
    mov [bx-1434], ')'
    mov [bx-1433], 1100b
    sub bx, 12    
    RET
    
deplacement_droite4:
    cmp [bx+10], 0B1h
    je changedl1 
    mov [bx-1444], 0
    mov [bx-1442], '('
    mov [bx-1441], 1100b
    mov [bx-1440], '-'
    mov [bx-1439], 1100b
    mov [bx-1438], 'O'
    mov [bx-1437], 1100b
    mov [bx-1436], '-'
    mov [bx-1435], 1100b
    mov [bx-1434], ')'
    mov [bx-1433], 1100b
    sub bx, 12    
    RET
    
deplacement_gauche1:
    mov [bx+4], 0
    mov [bx+2], ')'
    mov [bx+1], 1100b
    mov [bx], '-'
    mov [bx-1], 1100b
    mov [bx-2], 'O'
    mov [bx-3], 1100b
    mov [bx-4], '-'
    mov [bx-5], 1100b
    mov [bx-6], '('
    mov [bx-7], 1100b
    
    mov [bx-476], 0
    mov [bx-478], ')'
    mov [bx-479], 1100b
    mov [bx-480], '-'
    mov [bx-481], 1100b
    mov [bx-482], 'O'
    mov [bx-483], 1100b
    mov [bx-484], '-'
    mov [bx-485], 1100b
    mov [bx-486], '('
    mov [bx-487], 1100b
    
    mov [bx-956], 0
    mov [bx-958], ')'
    mov [bx-959], 1100b
    mov [bx-960], '-'
    mov [bx-961], 1100b
    mov [bx-962], 'O'
    mov [bx-963], 1100b
    mov [bx-964], '-'
    mov [bx-965], 1100b
    mov [bx-966], '('
    mov [bx-967], 1100b
    
    mov [bx-1436], 0
    mov [bx-1438], ')'
    mov [bx-1439], 1100b
    mov [bx-1440], '-'
    mov [bx-1441], 1100b
    mov [bx-1442], 'O'
    mov [bx-1443], 1100b
    mov [bx-1444], '-'
    mov [bx-1445], 1100b
    mov [bx-1446], '('
    mov [bx-1447], 1100b
    cmp [bx-10], 0B1h
    je changedl0
    sub bx, 12
    RET
    
deplacement_gauche2:
    mov [bx-476], 0
    mov [bx-478], ')'
    mov [bx-479], 1100b
    mov [bx-480], '-'
    mov [bx-481], 1100b
    mov [bx-482], 'O'
    mov [bx-483], 1100b
    mov [bx-484], '-'
    mov [bx-485], 1100b
    mov [bx-486], '('
    mov [bx-487], 1100b
    
    mov [bx-956], 0
    mov [bx-958], ')'
    mov [bx-959], 1100b
    mov [bx-960], '-'
    mov [bx-961], 1100b
    mov [bx-962], 'O'
    mov [bx-963], 1100b
    mov [bx-964], '-'
    mov [bx-965], 1100b
    mov [bx-966], '('
    mov [bx-967], 1100b
    
    mov [bx-1436], 0
    mov [bx-1438], ')'
    mov [bx-1439], 1100b
    mov [bx-1440], '-'
    mov [bx-1441], 1100b
    mov [bx-1442], 'O'
    mov [bx-1443], 1100b
    mov [bx-1444], '-'
    mov [bx-1445], 1100b
    mov [bx-1446], '('
    mov [bx-1447], 1100b 
    cmp [bx-10], 0B1h
    je changedl0
    sub bx, 12
    RET
    
deplacement_gauche3:
    mov [bx-956], 0
    mov [bx-958], ')'
    mov [bx-959], 1100b
    mov [bx-960], '-'
    mov [bx-961], 1100b
    mov [bx-962], 'O'
    mov [bx-963], 1100b
    mov [bx-964], '-'
    mov [bx-965], 1100b
    mov [bx-966], '('
    mov [bx-967], 1100b
    
    mov [bx-1436], 0
    mov [bx-1438], ')'
    mov [bx-1437], 1100b
    mov [bx-1440], '-'
    mov [bx-1439], 1100b
    mov [bx-1442], 'O'
    mov [bx-1441], 1100b
    mov [bx-1444], '-'
    mov [bx-1443], 1100b
    mov [bx-1446], '('
    mov [bx-1445], 1100b
    cmp [bx-10], 0B1h
    je changedl0
    sub bx, 12
    RET
    
deplacement_gauche4:
    mov [bx-1436], 0
    mov [bx-1438], ')'
    mov [bx-1439], 1100b
    mov [bx-1440], '-'
    mov [bx-1441], 1100b
    mov [bx-1442], 'O'
    mov [bx-1443], 1100b
    mov [bx-1444], '-'
    mov [bx-1445], 1100b
    mov [bx-1446], '('
    mov [bx-1447], 1100b
    cmp [bx-10], 0B1h
    je changedl0
    sub bx, 12
    RET
    
changedl1:
    mov dl, 1
    mov bx, 2078
    RET

changedl0:
    mov dl, 0
    mov bx, 2078
    RET

fin_partie:
    pusha
    XOR AX, AX 
    XOR BX, BX 
    XOR CX, CX
    XOR DX, DX
    mov ah, 6
    mov dx, 174fh
    int 10h
    popa
    
    mov cx, 80
    mov bx, 3840
    
    efface_bas_fin:
    mov [bx], 0
    mov [bx+1], 0
    add bx, 2
    loop efface_bas_fin
    
    ;G
    
    mov [370], 0B1h
    mov [371], 0100b
    mov [530], 0B1h
    mov [531], 0100b
    mov [690], 0B1h
    mov [691], 0100b
    mov [850], 0B1h
    mov [851], 0100b
    mov [1010], 0B1h
    mov [1011], 0100b
    mov [1170], 0B1h
    mov [1171], 0100b 
    mov [1330], 0B1h
    mov [1331], 0100b
    mov [1490], 0B1h
    mov [1491], 0100b
    
    mov [372], 0B1h
    mov [373], 0100b
    mov [532], 0B1h
    mov [533], 0100b
    mov [692], 0B1h
    mov [693], 0100b
    mov [852], 0B1h
    mov [853], 0100b
    mov [1012], 0B1h
    mov [1013], 0100b
    mov [1172], 0B1h
    mov [1173], 0100b 
    mov [1332], 0B1h
    mov [1333], 0100b
    mov [1492], 0B1h
    mov [1493], 0100b 
    
    mov [374], 0B1h
    mov [375], 0100b
    mov [534], 0B1h
    mov [535], 0100b 
    mov [1334], 0B1h
    mov [1335], 0100b
    mov [1494], 0B1h
    mov [1495], 0100b  
    
    mov [376], 0B1h
    mov [377], 0100b
    mov [536], 0B1h
    mov [537], 0100b
    mov [856], 0B1h
    mov [857], 0100b
    mov [1016], 0B1h
    mov [1017], 0100b
    mov [1336], 0B1h
    mov [1337], 0100b
    mov [1496], 0B1h
    mov [1497], 0100b  
    
    mov [378], 0B1h
    mov [379], 0100b
    mov [538], 0B1h
    mov [539], 0100b
    mov [858], 0B1h
    mov [859], 0100b
    mov [1018], 0B1h
    mov [1019], 0100b
    mov [1178], 0B1h
    mov [1179], 0100b 
    mov [1338], 0B1h
    mov [1339], 0100b
    mov [1498], 0B1h
    mov [1499], 0100b 
    
    mov [860], 0B1h
    mov [861], 0100b
    mov [1020], 0B1h
    mov [1021], 0100b
    mov [1180], 0B1h
    mov [1181], 0100b 
    mov [1340], 0B1h
    mov [1341], 0100b
    mov [1500], 0B1h
    mov [1501], 0100b
    
    ;A
    
    mov [386], 0B1h
    mov [387], 0100b
    mov [546], 0B1h
    mov [547], 0100b
    mov [706], 0B1h
    mov [707], 0100b
    mov [866], 0B1h
    mov [867], 0100b
    mov [1026], 0B1h
    mov [1027], 0100b
    mov [1186], 0B1h
    mov [1187], 0100b 
    mov [1346], 0B1h
    mov [1347], 0100b
    mov [1506], 0B1h
    mov [1507], 0100b 
    
    mov [388], 0B1h
    mov [389], 0100b
    mov [548], 0B1h
    mov [549], 0100b
    mov [708], 0B1h
    mov [709], 0100b
    mov [868], 0B1h
    mov [869], 0100b
    mov [1028], 0B1h
    mov [1029], 0100b
    mov [1188], 0B1h
    mov [1189], 0100b 
    mov [1348], 0B1h
    mov [1349], 0100b
    mov [1508], 0B1h
    mov [1509], 0100b 
    
    mov [390], 0B1h
    mov [391], 0100b
    mov [550], 0B1h
    mov [551], 0100b
    mov [1030], 0B1h
    mov [1031], 0100b
    mov [1190], 0B1h
    mov [1191], 0100b
    
    mov [392], 0B1h
    mov [393], 0100b
    mov [552], 0B1h
    mov [553], 0100b
    mov [1032], 0B1h
    mov [1033], 0100b
    mov [1192], 0B1h
    mov [1193], 0100b
    
    mov [394], 0B1h
    mov [395], 0100b
    mov [554], 0B1h
    mov [555], 0100b
    mov [714], 0B1h
    mov [715], 0100b
    mov [874], 0B1h
    mov [875], 0100b
    mov [1034], 0B1h
    mov [1035], 0100b
    mov [1194], 0B1h
    mov [1195], 0100b 
    mov [1354], 0B1h
    mov [1355], 0100b
    mov [1514], 0B1h
    mov [1515], 0100b  
    
    mov [396], 0B1h
    mov [397], 0100b
    mov [556], 0B1h
    mov [557], 0100b
    mov [716], 0B1h
    mov [717], 0100b
    mov [876], 0B1h
    mov [877], 0100b
    mov [1036], 0B1h
    mov [1037], 0100b
    mov [1196], 0B1h
    mov [1197], 0100b 
    mov [1356], 0B1h
    mov [1357], 0100b
    mov [1516], 0B1h
    mov [1517], 0100b
    
    ;M
    
    mov [402], 0B1h
    mov [403], 0100b
    mov [562], 0B1h
    mov [563], 0100b
    mov [722], 0B1h
    mov [723], 0100b
    mov [882], 0B1h
    mov [883], 0100b
    mov [1042], 0B1h
    mov [1043], 0100b
    mov [1202], 0B1h
    mov [1203], 0100b 
    mov [1362], 0B1h
    mov [1363], 0100b
    mov [1522], 0B1h
    mov [1523], 0100b
    
    mov [404], 0B1h
    mov [405], 0100b
    mov [564], 0B1h
    mov [565], 0100b
    mov [724], 0B1h
    mov [725], 0100b
    mov [884], 0B1h
    mov [885], 0100b
    mov [1044], 0B1h
    mov [1045], 0100b
    mov [1204], 0B1h
    mov [1205], 0100b 
    mov [1364], 0B1h
    mov [1365], 0100b
    mov [1524], 0B1h
    mov [1525], 0100b 
    
    mov [566], 0B1h
    mov [567], 0100b
    mov [726], 0B1h
    mov [727], 0100b
    mov [886], 0B1h
    mov [887], 0100b
    mov [1046], 0B1h
    mov [1047], 0100b 
    
    mov [728], 0B1h
    mov [729], 0100b
    mov [888], 0B1h
    mov [889], 0100b
    mov [1048], 0B1h
    mov [1049], 0100b
    mov [1208], 0B1h
    mov [1209], 0100b
    
    mov [570], 0B1h
    mov [571], 0100b
    mov [730], 0B1h
    mov [731], 0100b
    mov [890], 0B1h
    mov [891], 0100b
    mov [1050], 0B1h
    mov [1051], 0100b  
    
    mov [412], 0B1h
    mov [413], 0100b
    mov [572], 0B1h
    mov [573], 0100b
    mov [732], 0B1h
    mov [733], 0100b
    mov [892], 0B1h
    mov [893], 0100b
    mov [1052], 0B1h
    mov [1053], 0100b
    mov [1212], 0B1h
    mov [1213], 0100b 
    mov [1372], 0B1h
    mov [1373], 0100b
    mov [1532], 0B1h
    mov [1533], 0100b
    
    mov [414], 0B1h
    mov [415], 0100b
    mov [574], 0B1h
    mov [575], 0100b
    mov [734], 0B1h
    mov [735], 0100b
    mov [894], 0B1h
    mov [895], 0100b
    mov [1054], 0B1h
    mov [1055], 0100b
    mov [1214], 0B1h
    mov [1215], 0100b 
    mov [1374], 0B1h
    mov [1375], 0100b
    mov [1534], 0B1h
    mov [1535], 0100b 
    
    ;E
    
    mov [420], 0B1h
    mov [421], 0100b
    mov [580], 0B1h
    mov [581], 0100b
    mov [740], 0B1h
    mov [741], 0100b
    mov [900], 0B1h
    mov [901], 0100b
    mov [1060], 0B1h
    mov [1061], 0100b
    mov [1220], 0B1h
    mov [1221], 0100b 
    mov [1380], 0B1h
    mov [1381], 0100b
    mov [1540], 0B1h
    mov [1541], 0100b
    
    mov [422], 0B1h
    mov [423], 0100b
    mov [582], 0B1h
    mov [583], 0100b
    mov [742], 0B1h
    mov [743], 0100b
    mov [902], 0B1h
    mov [903], 0100b
    mov [1062], 0B1h
    mov [1063], 0100b
    mov [1222], 0B1h
    mov [1223], 0100b 
    mov [1382], 0B1h
    mov [1383], 0100b
    mov [1542], 0B1h
    mov [1543], 0100b
    
    mov [424], 0B1h
    mov [425], 0100b
    mov [584], 0B1h
    mov [585], 0100b
    mov [744], 0B1h
    mov [745], 0100b
    mov [904], 0B1h
    mov [905], 0100b
    mov [1064], 0B1h
    mov [1065], 0100b
    mov [1224], 0B1h
    mov [1225], 0100b
    mov [1384], 0B1h
    mov [1385], 0100b
    mov [1544], 0B1h
    mov [1545], 0100b 
    
    mov [426], 0B1h
    mov [427], 0100b
    mov [586], 0B1h
    mov [587], 0100b
    mov [906], 0B1h
    mov [907], 0100b
    mov [1066], 0B1h
    mov [1067], 0100b
    mov [1386], 0B1h
    mov [1387], 0100b
    mov [1546], 0B1h
    mov [1547], 0100b 
    
    mov [428], 0B1h
    mov [429], 0100b
    mov [588], 0B1h
    mov [589], 0100b
    mov [908], 0B1h
    mov [909], 0100b
    mov [1068], 0B1h
    mov [1069], 0100b
    mov [1388], 0B1h
    mov [1389], 0100b
    mov [1548], 0B1h
    mov [1549], 0100b 
    
    mov [430], 0B1h
    mov [431], 0100b
    mov [590], 0B1h
    mov [591], 0100b
    mov [910], 0B1h
    mov [911], 0100b
    mov [1070], 0B1h
    mov [1071], 0100b
    mov [1390], 0B1h
    mov [1391], 0100b
    mov [1550], 0B1h
    mov [1551], 0100b
    
    ;O
    
    mov [1970], 0B1h
    mov [1971], 0100b
    mov [2130], 0B1h
    mov [2131], 0100b
    mov [2290], 0B1h
    mov [2291], 0100b
    mov [2450], 0B1h
    mov [2451], 0100b
    mov [2610], 0B1h
    mov [2611], 0100b
    mov [2770], 0B1h
    mov [2771], 0100b
    mov [2930], 0B1h
    mov [2931], 0100b
    mov [3090], 0B1h
    mov [3091], 0100b
    
    mov [1972], 0B1h
    mov [1973], 0100b
    mov [2132], 0B1h
    mov [2133], 0100b
    mov [2292], 0B1h
    mov [2293], 0100b
    mov [2452], 0B1h
    mov [2453], 0100b
    mov [2612], 0B1h
    mov [2613], 0100b
    mov [2772], 0B1h
    mov [2773], 0100b
    mov [2932], 0B1h
    mov [2933], 0100b
    mov [3092], 0B1h
    mov [3093], 0100b
    
    mov [1974], 0B1h
    mov [1975], 0100b
    mov [2134], 0B1h
    mov [2135], 0100b
    mov [2934], 0B1h
    mov [2935], 0100b
    mov [3094], 0B1h
    mov [3095], 0100b
    
    mov [1976], 0B1h
    mov [1977], 0100b
    mov [2136], 0B1h
    mov [2137], 0100b
    mov [2936], 0B1h
    mov [2937], 0100b
    mov [3096], 0B1h
    mov [3097], 0100b
    
    mov [1978], 0B1h
    mov [1979], 0100b
    mov [2138], 0B1h
    mov [2139], 0100b
    mov [2298], 0B1h
    mov [2299], 0100b
    mov [2458], 0B1h
    mov [2459], 0100b
    mov [2618], 0B1h
    mov [2619], 0100b
    mov [2778], 0B1h
    mov [2779], 0100b
    mov [2938], 0B1h
    mov [2939], 0100b
    mov [3098], 0B1h
    mov [3099], 0100b
    
    mov [1980], 0B1h
    mov [1981], 0100b
    mov [2140], 0B1h
    mov [2141], 0100b
    mov [2300], 0B1h
    mov [2301], 0100b
    mov [2460], 0B1h
    mov [2461], 0100b
    mov [2620], 0B1h
    mov [2621], 0100b
    mov [2780], 0B1h
    mov [2781], 0100b
    mov [2940], 0B1h
    mov [2941], 0100b
    mov [3100], 0B1h
    mov [3101], 0100b
    
    ;V
    
    mov [1986], 0B1h
    mov [1987], 0100b
    mov [2146], 0B1h
    mov [2147], 0100b
    mov [2306], 0B1h
    mov [2307], 0100b 
    
    mov [1988], 0B1h
    mov [1989], 0100b
    mov [2148], 0B1h
    mov [2149], 0100b
    mov [2308], 0B1h
    mov [2309], 0100b
    mov [2468], 0B1h
    mov [2469], 0100b
    mov [2628], 0B1h
    mov [2629], 0100b
    mov [2788], 0B1h
    mov [2789], 0100b 
    
    mov [2470], 0B1h
    mov [2471], 0100b
    mov [2630], 0B1h
    mov [2631], 0100b
    mov [2790], 0B1h
    mov [2791], 0100b
    mov [2950], 0B1h
    mov [2951], 0100b
    mov [3110], 0B1h
    mov [3111], 0100b     
    
    mov [2792], 0B1h
    mov [2793], 0100b
    mov [2952], 0B1h
    mov [2953], 0100b
    mov [3112], 0B1h
    mov [3113], 0100b 
    
    mov [2474], 0B1h
    mov [2475], 0100b
    mov [2634], 0B1h
    mov [2635], 0100b
    mov [2794], 0B1h
    mov [2795], 0100b
    mov [2954], 0B1h
    mov [2955], 0100b
    mov [3114], 0B1h
    mov [3115], 0100b
    
    mov [1996], 0B1h
    mov [1997], 0100b
    mov [2156], 0B1h
    mov [2157], 0100b
    mov [2316], 0B1h
    mov [2317], 0100b
    mov [2476], 0B1h
    mov [2477], 0100b
    mov [2636], 0B1h
    mov [2637], 0100b
    mov [2796], 0B1h
    mov [2797], 0100b   
    
    mov [1998], 0B1h
    mov [1999], 0100b
    mov [2158], 0B1h
    mov [2159], 0100b
    mov [2318], 0B1h
    mov [2319], 0100b
    
    ;E
    
    mov [2004], 0B1h
    mov [2005], 0100b
    mov [2164], 0B1h
    mov [2165], 0100b
    mov [2324], 0B1h
    mov [2325], 0100b
    mov [2484], 0B1h
    mov [2485], 0100b
    mov [2644], 0B1h
    mov [2645], 0100b
    mov [2804], 0B1h
    mov [2805], 0100b
    mov [2964], 0B1h
    mov [2965], 0100b
    mov [3124], 0B1h
    mov [3125], 0100b
    
    mov [2006], 0B1h
    mov [2007], 0100b
    mov [2166], 0B1h
    mov [2167], 0100b
    mov [2326], 0B1h
    mov [2327], 0100b
    mov [2486], 0B1h
    mov [2487], 0100b
    mov [2646], 0B1h
    mov [2647], 0100b
    mov [2806], 0B1h
    mov [2807], 0100b
    mov [2966], 0B1h
    mov [2967], 0100b
    mov [3126], 0B1h
    mov [3127], 0100b
    
    mov [2008], 0B1h
    mov [2009], 0100b
    mov [2168], 0B1h
    mov [2169], 0100b
    mov [2328], 0B1h
    mov [2329], 0100b
    mov [2488], 0B1h
    mov [2489], 0100b
    mov [2648], 0B1h
    mov [2649], 0100b
    mov [2808], 0B1h
    mov [2809], 0100b
    mov [2968], 0B1h
    mov [2969], 0100b
    mov [3128], 0B1h
    mov [3129], 0100b
    
    mov [2010], 0B1h
    mov [2011], 0100b
    mov [2170], 0B1h
    mov [2171], 0100b
    mov [2490], 0B1h
    mov [2491], 0100b
    mov [2650], 0B1h
    mov [2651], 0100b
    mov [2970], 0B1h
    mov [2971], 0100b
    mov [3130], 0B1h
    mov [3131], 0100b
    
    mov [2012], 0B1h
    mov [2013], 0100b
    mov [2172], 0B1h
    mov [2173], 0100b
    mov [2492], 0B1h
    mov [2493], 0100b
    mov [2652], 0B1h
    mov [2653], 0100b
    mov [2972], 0B1h
    mov [2973], 0100b
    mov [3132], 0B1h
    mov [3133], 0100b
    
    mov [2014], 0B1h
    mov [2015], 0100b
    mov [2174], 0B1h
    mov [2175], 0100b
    mov [2494], 0B1h
    mov [2495], 0100b
    mov [2654], 0B1h
    mov [2655], 0100b
    mov [2974], 0B1h
    mov [2975], 0100b
    mov [3134], 0B1h
    mov [3135], 0100b
    
    ;R
    
    mov [2020], 0B1h
    mov [2021], 0100b
    mov [2180], 0B1h
    mov [2181], 0100b
    mov [2340], 0B1h
    mov [2341], 0100b
    mov [2500], 0B1h
    mov [2501], 0100b
    mov [2660], 0B1h
    mov [2661], 0100b
    mov [2820], 0B1h
    mov [2821], 0100b
    mov [2980], 0B1h
    mov [2981], 0100b
    mov [3140], 0B1h
    mov [3141], 0100b
    
    mov [2022], 0B1h
    mov [2023], 0100b
    mov [2182], 0B1h
    mov [2183], 0100b
    mov [2342], 0B1h
    mov [2343], 0100b
    mov [2502], 0B1h
    mov [2503], 0100b
    mov [2662], 0B1h
    mov [2663], 0100b
    mov [2822], 0B1h
    mov [2823], 0100b
    mov [2982], 0B1h
    mov [2983], 0100b
    mov [3142], 0B1h
    mov [3143], 0100b 
    
    mov [2024], 0B1h
    mov [2025], 0100b
    mov [2184], 0B1h
    mov [2185], 0100b
    mov [2664], 0B1h
    mov [2665], 0100b
    mov [2824], 0B1h
    mov [2825], 0100b
    
    mov [2026], 0B1h
    mov [2027], 0100b
    mov [2186], 0B1h
    mov [2187], 0100b
    mov [2666], 0B1h
    mov [2667], 0100b
    mov [2826], 0B1h
    mov [2827], 0100b
    mov [2986], 0B1h
    mov [2987], 0100b
    
    mov [2028], 0B1h
    mov [2029], 0100b
    mov [2188], 0B1h
    mov [2189], 0100b
    mov [2348], 0B1h
    mov [2349], 0100b
    mov [2508], 0B1h
    mov [2509], 0100b
    mov [2668], 0B1h
    mov [2669], 0100b
    mov [2828], 0B1h
    mov [2829], 0100b
    mov [2988], 0B1h
    mov [2989], 0100b
    mov [3148], 0B1h
    mov [3149], 0100b
    
    mov [2030], 0B1h
    mov [2031], 0100b
    mov [2190], 0B1h
    mov [2191], 0100b
    mov [2350], 0B1h
    mov [2351], 0100b
    mov [2510], 0B1h
    mov [2511], 0100b
    mov [2990], 0B1h
    mov [2991], 0100b
    mov [3150], 0B1h
    mov [3151], 0100b
    
rejouer:  
    mov cx, 3
    push_pr:
    mov bx, 3730
    mov [bx], 'P'
    mov [bx+1], 1010b 
    mov [bx+2], 'o'
    mov [bx+3], 1010b
    mov [bx+4], 'u'
    mov [bx+5], 1010b
    mov [bx+6], 'r'
    mov [bx+7], 1010b
    mov [bx+10], 'R'
    mov [bx+11], 1010b
    mov [bx+12], 'e' 
    mov [bx+13], 1010b
    mov [bx+14], 'j' 
    mov [bx+15], 1010b
    mov [bx+16], 'o' 
    mov [bx+17], 1010b
    mov [bx+18], 'u' 
    mov [bx+19], 1010b
    mov [bx+20], 'e' 
    mov [bx+21], 1010b
    mov [bx+22], 'r' 
    mov [bx+23], 1010b
    mov [bx+26], 'A' 
    mov [bx+27], 1010b
    mov [bx+28], 'p' 
    mov [bx+29], 1010b
    mov [bx+30], 'p' 
    mov [bx+31], 1010b
    mov [bx+32], 'u' 
    mov [bx+33], 1010b
    mov [bx+34], 'y' 
    mov [bx+35], 1010b
    mov [bx+36], 'e' 
    mov [bx+37], 1010b
    mov [bx+38], 'z' 
    mov [bx+39], 1010b
    mov [bx+42], 's' 
    mov [bx+43], 1010b
    mov [bx+44], 'u' 
    mov [bx+45], 1010b
    mov [bx+46], 'r' 
    mov [bx+47], 1010b
    mov [bx+50], 'P' 
    mov [bx+51], 1010b
    loop push_pr
    
    mov cx, 3
    push_pr1:
    mov [bx], 0
    mov [bx+2], 0
    mov [bx+4], 0
    mov [bx+6], 0
    mov [bx+10], 0
    mov [bx+12], 0
    mov [bx+14], 0
    mov [bx+16], 0
    mov [bx+18], 0
    mov [bx+20], 0
    mov [bx+22], 0
    mov [bx+26], 0
    mov [bx+28], 0
    mov [bx+30], 0
    mov [bx+32], 0
    mov [bx+34], 0
    mov [bx+36], 0
    mov [bx+38], 0  
    mov [bx+42], 0
    mov [bx+44], 0
    mov [bx+46], 0
    mov [bx+50], 0
    
    loop push_pr1
        
    mov ah, 1
    int 16h
    cmp ah, 0x19h
    je affichage_niveau1
loop rejouer
    
    DEFINE_PRINT_NUM
    DEFINE_PRINT_NUM_UNS
END         
    

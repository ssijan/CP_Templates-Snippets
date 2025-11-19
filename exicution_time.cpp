mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
/*Starting point
auto begin = std::chrono::high_resolution_clock::now();
  !!!
  !!!
  !!!
auto end = std::chrono::high_resolution_clock::now();
auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
*/

class Sum {
  public static void main(String[] a){
    System.out.println(new Test().Sum(100));
  }
}

class Test {
  public int Sum(int num) {
    int sum;
    sum = 0;
    if (sum < 0)
    {
    while (0 < num) {
      sum = sum + num;
      num = num - 1;
    }
    System.out.println(10);
  }
  else
  {
    System.out.println(1000);
  }
    return sum;
  }
}


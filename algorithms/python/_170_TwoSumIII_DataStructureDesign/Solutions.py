class TwoSum:
    def __init__(self):
        self.nums = {}

    def add(self, number):
        """
        @param number: An integer
        @return: nothing
        """
        # write your code here
        if number in self.nums:
            self.nums[number] += 1
        else:
            self.nums[number] = 1

    def find(self, value):
        """
        @param value: An integer
        @return: Find if there exists any pair of numbers which sum is equal to the value.
        """
        # write your code here
        for num, count in self.nums.items():
            if value - num in self.nums and (value != 2 * num or count > 1):
                return True
        return False


if __name__ == "__main__":
    so = TwoSum()
    so.add(1)
    so.add(3)
    so.add(5)
    print(so.find(4))
    print(so.find(7))

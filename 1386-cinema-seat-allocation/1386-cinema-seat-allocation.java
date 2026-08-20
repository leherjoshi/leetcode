class Solution {
    public int maxNumberOfFamilies(int n, int[][] reservedSeats) {
        Map<Integer, HashSet<Integer>> seats = new HashMap<>();

        for(int[] r : reservedSeats) {
            int row = r[0];
            int seat = r[1];

            if(seat >= 2 && seat <= 5) {
                if(!seats.containsKey(row)) {
                    seats.put(row, new HashSet<>());
                }
                seats.get(row).add(0);
            }

            if(seat >= 4 && seat <= 7) {
                if(!seats.containsKey(row)) {
                    seats.put(row, new HashSet<>());
                }
                seats.get(row).add(1);
            }

            if(seat >= 6 && seat <= 9) {
                if(!seats.containsKey(row)) {
                    seats.put(row, new HashSet<>());
                }
                seats.get(row).add(2);
            }
        }

        int total = 2 * n;

        for(HashSet<Integer> groups : seats.values()) {
            if(groups.size() == 3) {
                total -= 2;
            } else {
                total -= 1;
            }
        }

        return total;
    }
}
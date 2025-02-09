import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n;

        System.out.println("Enter number of processes:");
        n = input.nextInt();

        int[][] A = new int[n][6]; // [Process ID, AT, BT, WT, TAT, CT]
        List<int[]> ganttChart = new ArrayList<>(); // Store execution order

        System.out.println("Enter Arrival Time and Burst Time:");
        for (int i = 0; i < n; i++) {
            System.out.print("P" + (i + 1) + " Arrival Time: ");
            A[i][1] = input.nextInt(); // Arrival Time
            System.out.print("P" + (i + 1) + " Burst Time: ");
            A[i][2] = input.nextInt(); // Burst Time
            A[i][0] = i + 1; // Process ID
        }

        // Sort processes by Arrival Time first
        Arrays.sort(A, Comparator.comparingInt(a -> a[1]));

        boolean[] completed = new boolean[n]; // Tracks completed processes
        int completedCount = 0, currentTime = 0, totalWT = 0, totalTAT = 0;

        while (completedCount < n) {
            int idx = -1;
            int minBT = Integer.MAX_VALUE;

            // Find the process with the shortest Burst Time that has arrived
            for (int i = 0; i < n; i++) {
                if (!completed[i] && A[i][1] <= currentTime) {
                    if (A[i][2] < minBT) { // Shortest Job First
                        minBT = A[i][2];
                        idx = i;
                    }
                }
            }

            if (idx == -1) {
                // No process is ready, CPU idle time
                ganttChart.add(new int[]{-1, currentTime, currentTime + 1}); // -1 represents idle time
                currentTime++;
            } else {
                int AT = A[idx][1]; // Arrival Time
                int BT = A[idx][2]; // Burst Time

                // Waiting Time = Start time - Arrival time
                A[idx][3] = currentTime - AT;
                totalWT += A[idx][3];

                // Turnaround Time = Waiting Time + Burst Time
                A[idx][4] = A[idx][3] + BT;
                totalTAT += A[idx][4];

                // Completion Time = Current Time + Burst Time
                A[idx][5] = currentTime + BT;

                // Add to Gantt Chart
                ganttChart.add(new int[]{A[idx][0], currentTime, A[idx][5]});

                // Move time forward and mark process as completed
                currentTime += BT;
                completed[idx] = true;
                completedCount++;
            }
        }

        // Sort processes by Process ID to print table in order
        Arrays.sort(A, Comparator.comparingInt(a -> a[0]));

        System.out.println("\nP\tAT\tBT\tWT\tTAT\tCT");
        for (int[] process : A) {
            System.out.println("P" + process[0] + "\t" + process[1] + "\t" + process[2] + "\t" + process[3] + "\t" + process[4] + "\t" + process[5]);
        }

        System.out.println("\nAverage Waiting Time = " + (float) totalWT / n);
        System.out.println("Average Turnaround Time = " + (float) totalTAT / n);

        // Display Gantt Chart
        System.out.println("\nGantt Chart:");
        System.out.print(" ");

        for (int[] event : ganttChart) {
            if (event[0] == -1) {
                System.out.print("Idle   ");
            } else {
                System.out.print(" P" + event[0] + "  ");
            }
        }
        System.out.println();

        for (int[] event : ganttChart) {
            System.out.print(event[1] + "\t  ");
        }
        System.out.println(currentTime);
    }
}

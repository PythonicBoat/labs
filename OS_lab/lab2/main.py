def fifo(page_ref_string, num_frames):
  """
  Simulates FIFO (First-In-First-Out) page replacement algorithm.

  Args:
      page_ref_string: List representing the page reference string.
      num_frames: Number of available page frames.

  Returns:
      Number of page faults.
  """
  queue = []  # Queue to represent page frames
  page_faults = 0
  for page in page_ref_string:
    if page not in queue:
      if len(queue) == num_frames:
        queue.pop(0)  # Remove the oldest element (FIFO)
      page_faults += 1
    queue.append(page)  # Add the page to the queue
  return page_faults

def lru(page_ref_string, num_frames):
  """
  Simulates LRU (Least Recently Used) page replacement algorithm.

  Args:
      page_ref_string: List representing the page reference string.
      num_frames: Number of available page frames.

  Returns:
      Number of page faults.
  """
  page_dict = {}  # Dictionary to store page access history
  queue = []  # Queue to represent page frames
  page_faults = 0
  for page in page_ref_string:
    if page not in queue:
      if len(queue) == num_frames:
        least_recently_used = min(page_dict, key=page_dict.get)  # Find least recently used page
        queue.remove(least_recently_used)
        del page_dict[least_recently_used]  # Remove from dictionary
      page_faults += 1
    else:
      del page_dict[page]  # Remove from dictionary for update
    page_dict[page] = len(page_ref_string)  # Update access time
    queue.append(page)  # Add the page to the queue
  return page_faults

def opt(page_ref_string, num_frames):
  """
  Simulates OPT (Optimal) page replacement algorithm (for comparison).

  Args:
      page_ref_string: List representing the page reference string.
      num_frames: Number of available page frames.

  Returns:
      Number of page faults.
  """
  page_faults = 0
  frames = [None] * num_frames  # List to represent page frames
  for i in range(len(page_ref_string)):
    if page_ref_string[i] not in frames:
      # Find the farthest used page in the future (optimal, but not practical)
      farthest_used = -1
      for j in range(i + 1, len(page_ref_string)):
        if page_ref_string[j] in frames:
          farthest_used = j
          break
      if farthest_used == -1:  # No page will be used in the future
        victim = 0  # Replace any page
      else:
        victim = frames.index(next(iter(set(frames) - set(page_ref_string[i:farthest_used + 1]))))
      frames[victim] = page_ref_string[i]
      page_faults += 1
    else:
      # Page already in memory, no replacement needed
      pass
  return page_faults

# Provided values
x = 2206065  # Not used in this code
f = 2
page_ref_string = [2, 3, 5, 6, 7, 'a', 1, 7, 2, 3, 1, 'b', 2, 4]

# Calculate page faults for each algorithm
fifo_faults = fifo(page_ref_string, f)
lru_faults = lru(page_ref_string, f)
opt_faults = opt(page_ref_string, f)

# Print results
print(f"Page faults in FIFO replacement: {fifo_faults}")
print(f"Page faults in LRU replacement: {lru_faults}")
print(f"Page faults in OPT replacement: {opt_faults}")

def countCombinations(self, pieces: List[str], positions: List[List[int]]) -> int:
  n = len(pieces)
  rook_dirs = [(1, 0), (0, 1), (-1, 0), (0, -1)]
  bishop_dirs = [(1, 1), (-1, 1), (-1, -1), (1, -1)]
  
  dir_map = {
      'rook': rook_dirs + [(0, 0)],
      'bishop': bishop_dirs + [(0, 0)],
      'queen': rook_dirs + bishop_dirs + [(0, 0)]
  }
  
  # count num of moves can be made given positions and directions
  def count_moves(positions, directions):
      # if all pieces reached destination, there's no more moves
      if all(direction == (0, 0) for direction in directions):
          return 0
      
      # do the move
      new_positions = [(i + di, j + dj) 
                        for (i, j), (di, dj) in zip(positions, directions)
                        if 1 <= i + di <= 8 and 1 <= j + dj <= 8]
      
      # if any pieces hit the wall, or they are in the same position
      if len(set(new_positions)) != n:
          return 0
      
      # found 1 valid move
      n_moves = 1
      
      # get all the possible directions, recursively call to count moves
      for new_direction in get_directions(directions, 0, []):
          n_moves += count_moves(new_positions, new_direction)
      return n_moves
  
  # backtrack to get all possible directions combination given last directions
  def get_directions(dirs, curr_idx, stack):
      if len(stack) == n:
          yield stack
          return
      for i in range(curr_idx, n):
          stack.append(dirs[i])
          for d in get_directions(dirs, i + 1, stack):
              yield d
          stack.pop()
          if any(dirs[i]):
              stack.append((0, 0))
              for d in get_directions(dirs, i + 1, stack):
                  yield d
              stack.pop()
  
  # backtrack to get all initial directions, call count_moves() when the stack is full 
  def init_directions_and_count(stack):
      n_moves = 0
      if len(stack) == n:
          n_moves += count_moves(positions, stack)
      else:            
          piece_to_add = pieces[len(stack)]            
          for direction in dir_map[piece_to_add]:
              stack.append(direction)
              n_moves += init_directions_and_count(stack)
              stack.pop()
      return n_moves
  
  # plus one for all pieces stays at initial locations
  return init_directions_and_count([]) + 1
# multiAgents.py
# --------------
# Licensing Information:  You are free to use or extend these projects for
# educational purposes provided that (1) you do not distribute or publish
# solutions, (2) you retain this notice, and (3) you provide clear
# attribution to UC Berkeley, including a link to http://ai.berkeley.edu.
# 
# Attribution Information: The Pacman AI projects were developed at UC Berkeley.
# The core projects and autograders were primarily created by John DeNero
# (denero@cs.berkeley.edu) and Dan Klein (klein@cs.berkeley.edu).
# Student side autograding was added by Brad Miller, Nick Hay, and
# Pieter Abbeel (pabbeel@cs.berkeley.edu).


from util import manhattanDistance
from game import Directions
import random, util

from game import Agent

class ReflexAgent(Agent):
    """
    A reflex agent chooses an action at each choice point by examining
    its alternatives via a state evaluation function.

    The code below is provided as a guide.  You are welcome to change
    it in any way you see fit, so long as you don't touch our method
    headers.
    """


    def getAction(self, gameState):
        """
        You do not need to change this method, but you're welcome to.

        getAction chooses among the best options according to the evaluation function.

        Just like in the previous project, getAction takes a GameState and returns
        some Directions.X for some X in the set {NORTH, SOUTH, WEST, EAST, STOP}
        """
        # Collect legal moves and successor states
        legalMoves = gameState.getLegalActions()

        # Choose one of the best actions
        scores = [self.evaluationFunction(gameState, action) for action in legalMoves]
        bestScore = max(scores)
        bestIndices = [index for index in range(len(scores)) if scores[index] == bestScore]
        chosenIndex = random.choice(bestIndices) # Pick randomly among the best

        "Add more of your code here if you want to"

        return legalMoves[chosenIndex]

    def evaluationFunction(self, currentGameState, action):
        """
        Design a better evaluation function here.

        The evaluation function takes in the current and proposed successor
        GameStates (pacman.py) and returns a number, where higher numbers are better.

        The code below extracts some useful information from the state, like the
        remaining food (newFood) and Pacman position after moving (newPos).
        newScaredTimes holds the number of moves that each ghost will remain
        scared because of Pacman having eaten a power pellet.

        Print out these variables to see what you're getting, then combine them
        to create a masterful evaluation function.
        """
        # Useful information you can extract from a GameState (pacman.py)
        successorGameState = currentGameState.generatePacmanSuccessor(action)
        newPos = successorGameState.getPacmanPosition()
        newFood = successorGameState.getFood()
        newGhostStates = successorGameState.getGhostStates()
        newScaredTimes = [ghostState.scaredTimer for ghostState in newGhostStates]

        "*** YOUR CODE HERE ***"
        newFood = newFood.asList()
        ghostPositions = [ghost.getPosition() for ghost in newGhostStates]
        scared = min(newScaredTimes) > 0

        if not scared and newPos in ghostPositions or len(ghostPositions) == 0:
            return -1
        if newPos in newFood or len(newFood) == 0:
            return 1
 
        closestFoodDist = min([util.manhattanDistance(food_pos, newPos) for food_pos in newFood])
        closestGhostDist = min([util.manhattanDistance(ghost_pos, newPos) for ghost_pos in ghostPositions])
        if(closestGhostDist < 4):
            return -250

        return 3.0/closestFoodDist - 1.0/closestGhostDist  + (successorGameState.getScore() - currentGameState.getScore())


def scoreEvaluationFunction(currentGameState):
    """
    This default evaluation function just returns the score of the state.
    The score is the same one displayed in the Pacman GUI.

    This evaluation function is meant for use with adversarial search agents
    (not reflex agents).
    """
    return currentGameState.getScore()

class MultiAgentSearchAgent(Agent):
    """
    This class provides some common elements to all of your
    multi-agent searchers.  Any methods defined here will be available
    to the MinimaxPacmanAgent, AlphaBetaPacmanAgent & ExpectimaxPacmanAgent.

    You *do not* need to make any changes here, but you can if you want to
    add functionality to all your adversarial search agents.  Please do not
    remove anything, however.

    Note: this is an abstract class: one that should not be instantiated.  It's
    only partially specified, and designed to be extended.  Agent (game.py)
    is another abstract class.
    """

    def __init__(self, evalFn = 'scoreEvaluationFunction', depth = '2'):
        self.index = 0 # Pacman is always agent index 0
        self.evaluationFunction = util.lookup(evalFn, globals())
        self.depth = int(depth)

class MinimaxAgent(MultiAgentSearchAgent):
    """
    Your minimax agent (question 2)
    """

    def getAction(self, gameState):
        """
        Returns the minimax action from the current gameState using self.depth
        and self.evaluationFunction.

        Here are some method calls that might be useful when implementing minimax.

        gameState.getLegalActions(agentIndex):
        Returns a list of legal actions for an agent
        agentIndex=0 means Pacman, ghosts are >= 1

        gameState.generateSuccessor(agentIndex, action):
        Returns the successor game state after an agent takes an action

        gameState.getNumAgents():
        Returns the total number of agents in the game

        gameState.isWin():
        Returns whether or not the game state is a winning state

        gameState.isLose():
        Returns whether or not the game state is a losing state
        """
        "*** YOUR CODE HERE ***"
        bestScore, dic = self.maxValue(gameState, self.depth, 0)
        return dic[bestScore]
        
            
    def maxValue(self, gameState, depth, player):
        if depth == 0 or gameState.isWin() or gameState.isLose():
            return self.evaluationFunction(gameState), None
        
        best_action = None
        ghostScore = 0
        best_value = float("-inf")
        dic = {}
        if player == 0:
            actions = gameState.getLegalActions(player)
            for action in actions:
                ghostScore = self.minValue(gameState.generateSuccessor(player, action), depth, player + 1)                
                dic[ghostScore] = action
                
                if ghostScore > best_value:
                    best_value = ghostScore

        return best_value, dic
        
    def minValue(self, gameState, depth, player):
        if depth == 0 or gameState.isWin() or gameState.isLose():
            return self.evaluationFunction(gameState)

        ghostScore = 0
        best_value = float("inf")
        actions = gameState.getLegalActions(player)

        for action in actions:
            if player == gameState.getNumAgents() - 1:
                ghostScore, _ = self.maxValue(gameState.generateSuccessor(player,action), depth - 1, 0)
            else:
                ghostScore = self.minValue(gameState.generateSuccessor(player,action), depth, player + 1)

            if ghostScore < best_value:
                best_value = ghostScore
        
        return best_value
    
    
class AlphaBetaAgent(MultiAgentSearchAgent):
    """
    Your minimax agent with alpha-beta pruning (question 3)
    """

    def getAction(self, gameState):
        """
        Returns the minimax action using self.depth and self.evaluationFunction
        """
        "*** YOUR CODE HERE ***"

        bestScore, dic = self.maxValue(gameState, self.depth, 0, float('-inf'), float('inf'))
        return dic[bestScore]
        
            
    def maxValue(self, gameState, depth, player, alpha, beta):
        if depth == 0 or gameState.isWin() or gameState.isLose():
            return self.evaluationFunction(gameState), None
        
        best_action = None
        ghostScore = 0
        best_value = float("-inf")
        dic = {}
        if player == 0:
            actions = gameState.getLegalActions(player)
            for action in actions:
                ghostScore= self.minValue(gameState.generateSuccessor(player, action), depth, player + 1, alpha, beta)

                dic[ghostScore] = action
                
                if ghostScore > best_value:
                    best_value = ghostScore

                alpha = max(alpha, ghostScore)

                if ghostScore > beta:
                    return ghostScore, dic

        return best_value, dic
    
        
    def minValue(self, gameState, depth, player, alpha, beta):
        if depth == 0 or gameState.isWin() or gameState.isLose():
            return self.evaluationFunction(gameState)

        ghostScore = 0
        best_value = float("inf")
        actions = gameState.getLegalActions(player)

        for action in actions:
            if player == gameState.getNumAgents() - 1:
                ghostScore , _ = self.maxValue(gameState.generateSuccessor(player,action), depth - 1, 0, alpha, beta)
            else:
                ghostScore = self.minValue(gameState.generateSuccessor(player,action), depth, player + 1, alpha, beta)

            if ghostScore < best_value:
                best_value = ghostScore

            beta = min(beta, ghostScore)

            if ghostScore < alpha:
                return ghostScore
            
        
        return best_value
       
    
class ExpectimaxAgent(MultiAgentSearchAgent):
    
      #Your expectimax agent (question 4)
    

    def getAction(self, gameState):
        """
        Returns the expectimax action using self.depth and self.evaluationFunction

        All ghosts should be modeled as choosing uniformly at random from their
        legal moves.
        """
        "*** YOUR CODE HERE ***"
        bestScore, dic = self.maxValue(gameState, self.depth, 0)
        return dic[bestScore]
        
          
    def maxValue(self, gameState, depth, player):
        if depth == 0 or gameState.isWin() or gameState.isLose():
            return self.evaluationFunction(gameState), None
        
        best_action = None
        ghostScore = 0
        best_value = float("-inf")
        dic = {}
        if player == 0:
            actions = gameState.getLegalActions(player)
            for action in actions:
                ghostScore = self.expectedValue(gameState.generateSuccessor(player, action), depth, player + 1)                
                dic[ghostScore] = action
                
                if ghostScore > best_value:
                    best_value = ghostScore

        return best_value, dic
        
    def expectedValue(self, gameState, depth, player):
        if depth == 0 or gameState.isWin() or gameState.isLose():
            return self.evaluationFunction(gameState)

        ghostScore = 0
        expectedValue = 0
        actions = gameState.getLegalActions(player)

        probability = 1.0 / len(actions)

        for action in actions:
            if player == gameState.getNumAgents() - 1:
                ghostScore, _ = self.maxValue(gameState.generateSuccessor(player,action), depth - 1, 0)
            else:
                ghostScore = self.expectedValue(gameState.generateSuccessor(player,action), depth, player + 1)

            expectedValue += probability * ghostScore

        
        return expectedValue
    

def betterEvaluationFunction(currentGameState):
    """
    Your extreme ghost-hunting, pellet-nabbing, food-gobbling, unstoppable
    evaluation function (question 5).

    DESCRIPTION: <write something here so we know what you did>
    """
    "*** YOUR CODE HERE ***"

    newPos = currentGameState.getPacmanPosition()
    newFood = currentGameState.getFood()
    newGhostStates = currentGameState.getGhostStates()
    newScaredTimes = [ghostState.scaredTimer for ghostState in newGhostStates]
    "*** YOUR CODE HERE ***"
    newFood = newFood.asList()
    ghostPositions = [ghost.getPosition() for ghost in newGhostStates]
    ghostDistances = [util.manhattanDistance(ghost_pos, newPos) ** 2 for ghost_pos in ghostPositions]
    foodDistances = [util.manhattanDistance(newPos, food_pos)for food_pos in newFood]

    scared = min(newScaredTimes) > 0

    currentScore = currentGameState.getScore()
    if not ghostPositions:
        closestGhostDist = 1
    else:
        closestGhostDist = min(ghostDistances)


    if not foodDistances:
        food_min = 1
        food_avg = 1
    else:
        food_min = min(ghostDistances)
        food_avg = sum([util.manhattanDistance(newPos, food_pos) for food_pos in newFood])/len(newFood)

    toAdd = -10 * len(foodDistances)
    if currentGameState.isWin():
        toAdd = 6000
    elif currentGameState.isLose():
        toAdd = -5000
  

    return currentScore  - 3 * sum(foodDistances) - 10 * len(foodDistances)  - 2 * sum(ghostDistances) + toAdd 
better = betterEvaluationFunction

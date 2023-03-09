#Complete this function so that it also works for L2 regularization:
def least_squares(X: np.array, y: np.array, alpha: float=0.0) -> np.array:
    """
    Perform linear regression via least squares, return coefficient

    :param numpy.array X: design matrix (n-sample as rows, p features as columns)
    :param numpy.array y: response vector (p elements)
    :param numpy.array alpha: regularization parameter (aka lambda; between 0 and inf)
    :return: linear regression coefficient found via ols
    :rtype: numpy.array
    """
    
    theta = np.linalg.inv(X.T.dot(X)).dot(X.T).dot(y)

    return theta
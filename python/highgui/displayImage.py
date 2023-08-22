import cv2

def main(argv):
    cv2.namedWindow(argv[1])
    arr = cv2.imread(argv[1])
    cv2.imshow(argv[1],arr)

    while 1:
        if cv2.waitKey(100) == 27:
            break
        # print("waited 100")
    cv2.destroyAllWindows()
    return


if __name__ == '__main__':
    import sys
    main(sys.argv)

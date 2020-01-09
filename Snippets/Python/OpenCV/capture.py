import cv2 as cv


def main():
    cap0 = cv.VideoCapture(0)
    # cap1 = cv.VideoCapture(1)
    while cap0.isOpened(): # and cap1.isOpened():
        ret0, frame0 = cap0.read()
        # ret1, frame1 = cap1.read()
        cv.imshow('capture0', frame0)
        # cv.imshow('capture1',frame1)
        if cv.waitKey(1) & 0xFF == ord('q'):
            break
    cap0.release()
    # cap1.release()
    cv.destroyAllWindows()


if __name__ == "__main__":
    main()

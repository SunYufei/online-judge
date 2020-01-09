import cv2
from sys import argv


if __name__ == "__main__":
    # 自定义摄像头
    if len(argv) > 1:
        cap = cv2.VideoCapture(int(argv[1]))
    else:
        cap = cv2.VideoCapture(0)

    face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')

    while cap.isOpened():
        _, frame = cap.read()

        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

        faces = face_cascade.detectMultiScale(gray,
                                              scaleFactor=1.2,
                                              minNeighbors=5,
                                              minSize=(32, 32))
        
        for (x, y, w, h) in faces:
            cv2.rectangle(frame,
                          (x, y),
                          (x + w, y + h),
                          (0, 0, 255),
                          2)

        cv2.imshow('Face Detection', frame)

        if cv2.waitKey(33) & 0xFF == ord('q'):
            break

    cap.release()
    cv2.destroyAllWindows()
